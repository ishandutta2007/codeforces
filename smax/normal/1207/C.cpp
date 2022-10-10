#include <bits/stdc++.h>
using namespace std;

long long dp[200000][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;

        dp[0][0] = a + 2 * b;
        dp[0][1] = LLONG_MAX / 2;
        for (int i=1; i<n; i++) {
            if (s[i] == '1')
                dp[i][0] = LLONG_MAX / 2;
            else
                dp[i][0] = min(dp[i-1][0], dp[i-1][1] + a) + a + b;
            dp[i][1] = min(dp[i-1][0] + a + b, dp[i-1][1]) + a + 2 * b;
        }

        cout << dp[n-1][0] << "\n";
    }

    return 0;
}