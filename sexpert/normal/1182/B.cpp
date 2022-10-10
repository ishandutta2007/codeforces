#include <bits/stdc++.h>
using namespace std;

char board[505][505];

int main() {
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> board[i][j];

    bool centered = false;
    int ox, oy;
    for(int i = 1; i < r - 1; i++) {
        for(int j = 1; j < c - 1; j++) {
            if(board[i][j] != '*') continue;
            if(board[i - 1][j] != '*') continue;
            if(board[i + 1][j] != '*') continue;
            if(board[i][j + 1] != '*') continue;
            if(board[i][j - 1] != '*') continue;
            ox = i;
            oy = j;
            centered = true;
            break;
        }
        if(centered)
            break;
    }
    if(!centered) {
        cout << "NO\n";
        return 0;
    }
    int nx = ox, ny = oy;
    while(nx - 1 >= 0 && board[nx - 1][oy] == '*') {
        board[nx - 1][oy] = '.';
        nx--;
    }
    nx = ox;
    while(nx + 1 < r && board[nx + 1][oy] == '*') {
        board[nx + 1][oy] = '.';
        nx++;
    }
    nx = ox;
    while(ny - 1 >= 0 && board[ox][ny - 1] == '*') {
        board[ox][ny - 1] = '.';
        ny--;
    }
    ny = oy;
    while(ny + 1 < c && board[ox][ny + 1] == '*') {
        board[ox][ny + 1] = '.';
        ny++;
    }
    board[ox][oy] = '.';

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(board[i][j] != '.') {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
}