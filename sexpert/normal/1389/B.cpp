#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;
ll dp[MAXN][6][2], a[MAXN];

void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 0; j <= 5; j++)
            dp[i][j][0] = dp[i][j][1] = 0;
    }
    dp[0][0][0] = a[1];
    for(int mo = 0; mo < k; mo++) {
        for(int lf = 0; lf <= z; lf++) {
            if(dp[mo][lf][0] == 0 && dp[mo][lf][1] == 0)
                continue;
            int pos = 1 + mo - 2*lf;
            dp[mo + 1][lf][0] = max(dp[mo + 1][lf][0], dp[mo][lf][0] + a[pos + 1]);
            dp[mo + 1][lf][0] = max(dp[mo + 1][lf][0], dp[mo][lf][1] + a[pos + 1]);
            if(pos > 1 && lf < z)
                dp[mo + 1][lf + 1][1] = max(dp[mo + 1][lf + 1][1], dp[mo][lf][0] + a[pos - 1]);
        }
    }
    ll ans = 0;
    for(int lf = 0; lf <= z; lf++) {
        ans = max(ans, dp[k][lf][0]);
        ans = max(ans, dp[k][lf][1]);
    }
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