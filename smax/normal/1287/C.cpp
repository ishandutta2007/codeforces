#include <bits/stdc++.h>
using namespace std;

int p[100], dp[100][100][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> p[i];

    // dp[i][j][k] - minimum complexity of first i bulbs using j even bulbs, last bulb is of parity k

    memset(dp, 127, sizeof(dp));
    if (p[0] == 0)
        dp[0][1][0] = dp[0][0][1] = 0;
    else if (p[0] % 2 == 0)
        dp[0][1][0] = 0;
    else
        dp[0][0][1] = 0;
    for (int i=1; i<n; i++)
        for (int j=0; j<n; j++) {
            if (p[i] != 0) {
                if (p[i] % 2 == 0 && j > 0)
                    dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j-1][1] + 1);
                else if (p[i] % 2 == 1)
                    dp[i][j][1] = min(dp[i-1][j][0] + 1, dp[i-1][j][1]);
            } else {
                if (j > 0) dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j-1][1] + 1);
                dp[i][j][1] = min(dp[i-1][j][0] + 1, dp[i-1][j][1]);
            }
        }

    cout << min(dp[n-1][n/2][0], dp[n-1][n/2][1]) << "\n";

    return 0;
}