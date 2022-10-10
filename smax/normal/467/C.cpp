#include <bits/stdc++.h>
using namespace std;

long long p[5001], dp[5001][5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    p[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        p[i] += p[i-1];
    }

    memset(dp, 128, sizeof(dp));
    for (int i=0; i<n; i++)
        dp[i][0] = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=k; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (i >= m)
                dp[i][j] = max(dp[i][j], dp[i-m][j-1] + p[i] - p[i-m]);
        }

    cout << dp[n][k] << "\n";

    return 0;
}