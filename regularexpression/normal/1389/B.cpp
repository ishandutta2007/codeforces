#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18 + 7;

void upd(int &x, int y) {
    x = max(x, y);
}

const int N = 1e5 + 7;

int dp[N][6][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= z; ++j) {
                for (int f = 0; f < 2; ++f) dp[i][j][f] = -INF;
            }
        }
        dp[0][0][0] = a[0];
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= z; ++j) {
                for (int f = 0; f < 2; ++f) {
                    if (dp[i][j][f] == -INF) continue;
                    int pos = i - j;
                    if (pos + 1 < n && i < k) {
                        upd(dp[i + 1][j][0], dp[i][j][f] + a[pos + 1]);
                    }
                    if (pos - 1 >= 0 && j < z && f != 1) {
                        upd(dp[i][j + 1][1], dp[i][j][f] + a[pos - 1]);
                    }
                }
            }
        }
        int ans = -INF;
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= min(z, k - i); ++j) {
                for (int f = 0; f < 2; ++f) upd(ans, dp[i][j][f]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}