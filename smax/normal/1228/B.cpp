#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int h, w, grid[1000][1000] = {};
    cin >> h >> w;
    for (int i=0; i<h; i++) {
        int r;
        cin >> r;
        for (int j=0; j<r; j++)
            grid[i][j] = 1;
        if (r < w)
            grid[i][r] = 2;
    }
    for (int j=0; j<w; j++) {
        int c;
        cin >> c;
        for (int i=0; i<c; i++) {
            if (grid[i][j] == 2) {
                cout << "0\n";
                return 0;
            }
            grid[i][j] = 1;
        }
        if (c < h) {
            if (grid[c][j] == 1) {
                cout << "0\n";
                return 0;
            }
            grid[c][j] = 2;
        }
    }

    int ret = 1;
    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++)
            if (grid[i][j] == 0)
                ret = ret * 2 % MOD;

    cout << ret << "\n";

    return 0;
}