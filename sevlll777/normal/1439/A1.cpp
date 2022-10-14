#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> F(n);
        for (int i = 0; i < n; i++) cin >> F[i];
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (F[i][j] == '1') {
                    if (i && j) {
                        ans.pb({i, j, i - 1, j, i, j - 1});
                        ans.pb({i, j, i - 1, j - 1, i, j - 1});
                        ans.pb({i, j, i - 1, j - 1, i - 1, j});
                    } else if (i == 0 && j != m - 1) {
                        ans.pb({i, j, i + 1, j, i, j + 1});
                        ans.pb({i, j, i + 1, j + 1, i, j + 1});
                        ans.pb({i, j, i + 1, j + 1, i + 1, j});
                    } else if (i == 0) {
                        ans.pb({i, j, i + 1, j, i, j - 1});
                        ans.pb({i, j, i + 1, j - 1, i, j - 1});
                        ans.pb({i, j, i + 1, j - 1, i + 1, j});
                    } else if (j == 0 && i != n - 1) {
                        ans.pb({i, j, i + 1, j, i, j + 1});
                        ans.pb({i, j, i + 1, j + 1, i, j + 1});
                        ans.pb({i, j, i + 1, j + 1, i + 1, j});
                    } else {
                        ans.pb({i, j, i - 1, j, i, j + 1});
                        ans.pb({i, j, i - 1, j + 1, i, j + 1});
                        ans.pb({i, j, i - 1, j + 1, i - 1, j});
                    }
                }
            }
        }
        cout << ans.size() << '\n';
        for (auto tt : ans) {
            for (auto x : tt) cout << x + 1 << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
}