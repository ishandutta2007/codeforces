#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int grid[505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    if(r + c == 2) {
        cout << "0\n";
        return 0;
    }
    if(c == 1) {
        for(int i = 1; i <= r; i++)
            cout << i + 1 << '\n';
        return 0;
    }
    for(int n = 1; n <= r; n++) {
        for(int m = 1; m <= c; m++) {
            grid[n][m] = n * (r + m);
        }
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
}