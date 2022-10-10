#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<vector<int>> dp(2, vector<int>(n + 1, INF));
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        dp[1][i + 1] = min(dp[1][i + 1], dp[0][i] + v[i + 1]);
        dp[0][i + 1] = min(dp[0][i + 1], dp[1][i]);
        if(i + 2 <= n) {
            dp[1][i + 2] = min(dp[1][i + 2], dp[0][i] + v[i + 1] + v[i + 2]);
            dp[0][i + 2] = min(dp[0][i + 2], dp[1][i]);
        }
    }
    cout << min(dp[0][n], dp[1][n]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}