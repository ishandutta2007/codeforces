#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, p, k, x, y;
    cin >> n >> p >> k;
    string s;
    cin >> s >> x >> y;
    vector<int> dp(n);
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '0')
            dp[i] = x;
        if(i + k < n)
            dp[i] += dp[i + k];
    }
    int ans = INT_MAX;
    for(int i = p - 1; i < n; i++)
        ans = min(ans, dp[i] + y * (i - p + 1));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}