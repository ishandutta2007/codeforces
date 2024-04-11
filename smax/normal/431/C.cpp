#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[101][2] = {1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k, d;
    cin >> n >> k >> d;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=k && i-j>=0; j++) {
            dp[i][0] = (dp[i][0] + dp[i-j][0]) % MOD;
            if (j >= d)
                dp[i][1] = (dp[i][1] + dp[i-j][0]) % MOD;
            else
                dp[i][1] = (dp[i][1] + dp[i-j][1]) % MOD;
        }

    cout << dp[n][1] << "\n";

    return 0;
}