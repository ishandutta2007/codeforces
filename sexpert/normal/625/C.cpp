#include <bits/stdc++.h>
using namespace std;

int board[505][505];

int main() {
    int n, k;
    cin >> n >> k;
    int ctr = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < k; j++) {
            board[i][j] = ctr;
            ctr++;
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = k; j <= n; j++) {
            board[i][j] = ctr;
            if(j == k)
                sum += ctr;
            ctr++;
        }
    }
    cout << sum << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}