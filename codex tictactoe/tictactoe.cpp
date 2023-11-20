
#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "---------" << endl;
    }
}

bool checkWinner(const vector<vector<char>>& board, char symbol) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;  // Row win
        }
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;  // Column win
        }
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;  // Diagonal win
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;  // Diagonal win
    }
    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    // Check if the board is full
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;  // Board is not full
            }
        }
    }
    return true;  // Board is full
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);

        // Get user input for the next move
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Convert move to 0-based indices
        --move;
        int row = move / 3;
        int col = move % 3;

        // Check if the chosen cell is empty
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check for a winner or a tie
            if (checkWinner(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            } else if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a tie!" << endl;
                break;
            } else {
                // Switch to the other symbol for the next move
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. The chosen cell is already occupied. Try again." << endl;
        }
    }

    return 0;
}


