#include <iostream>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';

void displayBoard() {
    cout << "Tic-Tac-Toe Game" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;  
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;  
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;  
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;  
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move. Try again." << endl;
        makeMove();
    } else {
        board[row][col] = currentPlayer;
    }
}

void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
    currentPlayer = 'X';
}

int main() {
    char playAgain;
    do {
        resetBoard();
        while (true) {
            displayBoard();
            makeMove();

            if (isWinner()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            if (isDraw()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                break;
            }
            switchPlayer();
        }
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
