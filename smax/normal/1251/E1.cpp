#include <bits/stdc++.h>
using namespace std;

pair<int, int> mp[5000];
long long dp[5000][5000];

long long solve(int n, int u) {
    if (n == 0) {
        if (u >= mp[n].first)
            return 0;
        else
            return mp[n].second;
    }
    if (dp[n][u] != -1)
        return dp[n][u];

    dp[n][u] = solve(n - 1, u + 1) + mp[n].second;
    if (n + u >= mp[n].first)
        dp[n][u] = min(dp[n][u], solve(n - 1, u));

    return dp[n][u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> mp[i].first >> mp[i].second;

        sort(mp, mp + n);
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                dp[i][j] = -1;

        cout << solve(n - 1, 0) << "\n";
    }

    return 0;
}