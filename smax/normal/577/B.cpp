#include <bits/stdc++.h>
using namespace std;

int a[1000000], dp[1001][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    if (n > m) {
        cout << "YES\n";
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (dp[i][j] == -1)
                continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i+1][(j+a[i])%m] = max(dp[i+1][(j+a[i])%m], dp[i][j] + 1);
        }

    cout << (dp[n][0] > 0 ? "YES" : "NO") << "\n";

    return 0;
}