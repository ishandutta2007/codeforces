#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244853;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> stroki(n*m+1), pogi(n*m+1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                pogi[x].pb(j);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                stroki[x].pb(j);
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));
        for (int x = 1; x <= n * m; x++) {
            for (int i = 0; i < (int) pogi[x].size(); i++) {
                ans[stroki[x][i]][pogi[x][i]] = x;
            }
        }
        for (auto xx : ans) {
            for (auto x : xx) {
                cout << x << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}