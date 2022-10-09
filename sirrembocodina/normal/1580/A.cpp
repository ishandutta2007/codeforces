#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int get_sum(int xl, int yl, int xr, int yr, vector<vector<int>>& pref) {
    return pref[xr][yr] + pref[xl][yl] - pref[xl][yr] - pref[xr][yl];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        forn (i, n) {
            cin >> a[i];
        }
        vector<vector<int>> pref1(n, vector<int>(m + 1));
        forn (i, n) {
            forn (j, m) {
                pref1[i][j + 1] = pref1[i][j] + a[i][j] - '0';
            }
        }
        vector<vector<int>> pref(n + 1, vector<int>(m + 1));
        forn (j, m + 1) {
            forn (i, n) {
                pref[i + 1][j] = pref[i][j] + pref1[i][j];
            }
        }
        int ans = 16;
        forn (xl, n) {
            forn (yl, m) {
                for (int xr = xl + 4; xr < n; xr++) {
                    for (int yr = yl + 3; yr < m; yr++) {
                        int cur = get_sum(xl + 1, yl + 1, xr, yr, pref);
                        cur += xr - xl - 1 - get_sum(xl + 1, yl, xr, yl + 1, pref);
                        cur += yr - yl - 1 - get_sum(xl, yl + 1, xl + 1, yr, pref);
                        cur += yr - yl - 1 - get_sum(xr, yl + 1, xr + 1, yr, pref);
                        if (cur > ans) {
                            break;
                        }
                        cur += xr - xl - 1 - get_sum(xl + 1, yr, xr, yr + 1, pref);
                        ans = min(ans, cur);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}