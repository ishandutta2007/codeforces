#include <bits/stdc++.h>
using namespace std;
 
char board[505][505];
 
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
            board[i][j] = s[j];
    }
    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < n - 1; j++) {
            if(board[i][j] == 'X' && board[i - 1][j - 1] == 'X' && board[i + 1][j + 1] == 'X' && board[i + 1][j - 1] == 'X' && board[i - 1][j + 1] == 'X')
                ans++;
        }
    }
    cout << ans << endl;
}