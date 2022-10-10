#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

int board[505][505];

signed main() {
    ll sum = 0;
    int n, r, c;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) {
                r = i;
                c = j;
            }
        }
    }
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int x = (r == 0 ? 1 : 0);
    for(int j = 0; j < n; j++)
        sum += board[x][j];
    int rsum = 0;
    for(int j = 0; j < n; j++)
        rsum += board[r][j];
    board[r][c] = sum - rsum;
    if(board[r][c] <= 0) {
        cout << -1 << endl;
        return 0;
    }
    int csum = 0;
    for(int i = 0; i < n; i++) {
        csum = 0;
        for(int j = 0; j < n; j++)
            csum += board[i][j];
        if(csum != sum) {
            cout << -1 << endl;
            return 0;
        }
    }
    for(int j = 0; j < n; j++) {
        csum = 0;
        for(int i = 0; i < n; i++)
            csum += board[i][j];
        if(csum != sum) {
            cout << -1 << endl;
            return 0;
        }
    }
    csum = 0;
    for(int i = 0; i < n; i++)
        csum += board[i][i];
    if(csum != sum) {
        cout << -1 << endl;
        return 0;
    }
    csum = 0;
    for(int i = 0; i < n; i++)
        csum += board[i][n - 1 - i];
    if(csum != sum) {
        cout << -1 << endl;
        return 0;
    }
    cout << board[r][c] << endl;
}