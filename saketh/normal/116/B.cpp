#include <iostream>
using namespace std;
    char board[12][12];

int main() {
    int R, C;
    int a[20][20];
    
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i+1][j+1];
        }
    }

    int ans = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; j++) {
            if( board[i+1][j+1] == 'W' ){
                if (board[i][j+1] == 'P' || board[i+1][j] == 'P' || board[i+2][j+1] == 'P' || board[i+1][j+2] == 'P') {
                    ans++;
                }
            }
}}
         cout << ans << "\n";
         return 0;
}