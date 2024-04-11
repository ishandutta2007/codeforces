#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> ind(n);
        for (int i = 0; i < n; ++i) ind[i].push_back(-1);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ind[a - 1].push_back(i);
        }
        vector<int> mn(n + 1, 1e9);
        for (int i = 0; i < n; ++i) {
            ind[i].push_back(n);
            int mx = 0;
            for (int j = 0; j + 1 < ind[i].size(); ++j) mx = max(mx, ind[i][j + 1] - ind[i][j]);
            if (mx <= n) mn[mx] = min(mn[mx], i);
        }
        for (int i = 1; i <= n; ++i) {
            mn[i] = min(mn[i], mn[i - 1]);
            cout << (mn[i] == 1e9 ? -1 : mn[i] + 1) << " ";
        }
        cout << '\n';
    }
    return 0;
}