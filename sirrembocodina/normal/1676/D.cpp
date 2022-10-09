#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cur = 0;
                int dx[4] = {1, 1, -1, -1};
                int dy[4] = {1, -1, 1, -1};
                for (int dir = 0; dir < 4; dir++) {
                    int x = i, y = j;
                    while (0 <= x && x < n &&
                           0 <= y && y < m) {
                        cur += a[x][y];
                        x += dx[dir];
                        y += dy[dir];
                    }
                }
                cur -= 3 * a[i][j];
                ans = max(ans, cur);
            }
        }
        cout << ans << '\n';
    }
}