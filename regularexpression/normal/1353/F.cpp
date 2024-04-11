#include<bits/stdc++.h>
using namespace std;

#define int long long 

inline void upd(int &x, int y) {
    if (y < x) x = y;
}

const int INF = 2e18 + 7;
int a[105][105], dp[105][105];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> good;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                a[i][j] -= i + j;
                good.push_back(a[i][j]);
            }
        }
        sort(good.begin(), good.end());
        good.erase(unique(good.begin(), good.end()), good.end());
        int ans = INF;
        for (auto z : good) {
            if (z > a[0][0]) continue;
            dp[0][0] = a[0][0] - z;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == 0 && j == 0) continue;
                    dp[i][j] = INF;
                    if (z <= a[i][j]) {
                        if (i != 0) upd(dp[i][j], dp[i - 1][j] + a[i][j] - z);
                        if (j != 0) upd(dp[i][j], dp[i][j - 1] + a[i][j] - z);
                    }
                }
            }
            upd(ans, dp[n - 1][m - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}