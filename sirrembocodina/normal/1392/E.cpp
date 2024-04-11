#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0) {
                a[i][j] = 0;
            } else {
                a[i][j] = ((long long)(1)) << (j + i - 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        int sum;
        cin >> sum;
        int x = 0, y = 0;
        while (x != n - 1 || y != n - 1) {
            cout << x + 1 << " " << y + 1 << endl;
            if (x == n - 1) {
                y++;
            } else if (y == n - 1) {
                x++;
            } else if (a[x + 1][y]) {
                if (sum & a[x + 1][y]) {
                    x++;
                } else {
                    y++;
                }
            } else {
                if (sum & a[x][y + 1]) {
                    y++;
                } else {
                    x++;
                }
            }
        }
        cout << n << " " << n << endl;
    }
}