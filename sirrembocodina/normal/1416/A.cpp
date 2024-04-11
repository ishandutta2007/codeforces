#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        forn (i, n) {
            int x;
            cin >> x;
            x--;
            a[x].push_back(i);
        }
        vector<int> len(n, 2e9);
        vector<int> ans(n + 1, 2e9);
        forn (i, n) {
            if (a[i].empty()) {
                continue;
            }
            len[i] = max(a[i][0] + 1, n - a[i].back());
            forn (j, a[i].size() - 1) {
                len[i] = max(len[i], a[i][j + 1] - a[i][j]);
            }
            ans[len[i]] = min(ans[len[i]], i);
        }
        forn (i, n) {
            ans[i + 1] = min(ans[i + 1], ans[i]);
            if (ans[i + 1] > n) {
                cout << -1 << " ";
            } else {
                cout << ans[i + 1] + 1 << " ";
            }
        }
        cout << endl;
    }
}