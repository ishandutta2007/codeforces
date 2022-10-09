#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int mod = 998244353;

int32_t main() {
    __int128 t;
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        forn (i, n) {
            forn (j, n) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        int cnt = (n + 2) / 4;
        forn (i, cnt) {
            forn (j, cnt - i) {
                int x = 4 * j + 2 * i, y = 2 * i;
                if (n % 4 == 0) {
                    x++;
                }
                ans ^= a[x][y];
                ans ^= a[x + 1][y];
                if (i > 0) {
                    ans ^= a[x][n + 1 - y];
                    ans ^= a[x + 1][n + 1 - y];
                }
            }
        }
        if (n % 4) {
            cnt--;
        }
        forn (i, cnt) {
            forn (j, cnt - i) {
                int x = 2 * i, y = n - 1 - 4 * j - 2 * i;
                if (n % 4) {
                    y--;
                }
                ans ^= a[x][y];
                ans ^= a[x][y - 1];
                ans ^= a[n - 1 - x][y];
                ans ^= a[n - 1 - x][y - 1];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}