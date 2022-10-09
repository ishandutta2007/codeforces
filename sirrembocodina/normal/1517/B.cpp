#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<pair<int, int>> b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                b.push_back({a[i][j], i});
            }
        }
        sort(b.begin(), b.end());
        vector<int> cnt(n, 0);
        for (int i = 0; i < m; i++) {
            cnt[b[i].second]++;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sort(a[i].begin(), a[i].end());
            for (int j = m - sum; j < m; j++) {
                cout << a[i][j] << " ";
            }
            for (int j = 0; j < m - sum; j++) {
                cout << a[i][j] << " ";
            }
            sum += cnt[i];
        }
    }
}