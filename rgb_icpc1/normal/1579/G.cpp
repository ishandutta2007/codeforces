#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
const int INF = 1000000000;

int main() {
    int Tc;
    for(cin >> Tc ; Tc -- ; ) {
        int n;
        cin >> n;
        vector<int> a(n);
        int maxl = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxl = max(maxl, a[i]);
        }
        vector<vector<int>> dp(n + 1, vector<int>(2 * maxl + 1, INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int left = 0; left <= 2 * maxl; left++) {
                if (dp[i][left] == INF)
                    continue;
                dp[i + 1][max(left - a[i], 0)] = min(dp[i + 1][max(left - a[i], 0)], dp[i][left] + a[i]);
                if (left + a[i] < dp[i + 1].size()) {
                    dp[i + 1][left + a[i]] = min(dp[i + 1][left + a[i]], max(dp[i][left] - a[i], 0));
                }
            }
        }

        int ans = 2 * maxl + 1;
        for (int left = 0; left <= 2 * maxl; left++)
            ans = min(ans, left + dp[n][left]);
        cout << ans << endl;
    }
}