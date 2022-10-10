#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int dp[10000001][4] = {};
    dp[0][3] = 1;
    for (int i=1; i<=n; i++)
        for (int j=0; j<4; j++)
            for (int k=0; k<4; k++)
                if (j != k)
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;

    cout << dp[n][3] << "\n";

    return 0;
}