#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn (i, n) {
        cin >> a[i];
    }
    vector<vector<int>> ans(n, vector<int>(n, -1));
    for (int i = n - 1; i >= 0; i--) {
        int x = i, y = i;
        int k = a[i], col = k;
        while (k--) {
            ans[x][y] = col;
            if (x + 1 < n && ans[x + 1][y] == -1) {
                x++;
            } else {
                y--;
            }
        }
    }
    forn (i, n) {
        forn (j, i + 1) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}