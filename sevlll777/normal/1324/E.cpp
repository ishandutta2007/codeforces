#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> A(1 + n);
    for (int i = 1; i <= n; i++) cin >> A[i];
    vector<vector<int>> dp(n + 2, vector<int>(h + 2));
    for (int p = 1; p <= h; p++) {
        dp[0][p] = -1e9;
    }
    for (int i = 1; i <= n; i++) {
        for (int tm = 0; tm < h; tm++) {
            int x1 = (tm - A[i] + h) % h;
            dp[i][tm] = max(dp[i - 1][x1], dp[i - 1][(x1 + 1) % h]);
            if (l <= tm && tm <= r) dp[i][tm]++;
        }
    }
    int ans = 0;
    for (int tm = 0; tm <= h; tm++) {
        ans = max(ans, dp[n][tm]);
    }
    cout << ans;
}