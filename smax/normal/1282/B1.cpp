#include <bits/stdc++.h>
using namespace std;

int a[200000], dp[200001][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        for (int i=0; i<n; i++)
            cin >> a[i];

        sort(a, a + n);
        for (int i=1; i<=n; i++)
            dp[i][0] = dp[i][1] = INT_MAX;
        int ret = 0;
        dp[0][0] = dp[0][1] = 0;
        for (int i=0; i<=n; i++) {
            if (dp[i][0] <= p) {
                ret = max(ret, i);
                dp[i+1][0] = min(dp[i+1][0], dp[i][0] + a[i]);
                if (i + k <= n)
                    dp[i+k][1] = min(dp[i+k][1], dp[i][0] + a[i+k-1]);
            }
            if (dp[i][1] <= p) {
                ret = max(ret, i);
                if (i + k <= n)
                    dp[i+k][1] = min(dp[i+k][1], dp[i][1] + a[i+k-1]);
            }
        }

        cout << ret << "\n";
    }

    return 0;
}