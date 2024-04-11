#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    ll a, b;
    cin >> n >> a >> b;
    ll def = a * n + b * (n + 1);
    string s;
    cin >> s;
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    dp[0][1] = 1e18;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + a);
        dp[i][1] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + b);
        if(s[i - 1] == '1') {
            dp[i][0] = 1e18;
            dp[i][1] = dp[i - 1][1] + b;
        }
    }
    cout << def + dp[n][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}