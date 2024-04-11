#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[105][105];
int pre[105], cur[26];
const ll INF = 1e15;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k >> s;
    dp[0][0] = 1;

    for(int p = 1; p <= n; p++) {
        int x = s[p - 1] - 'a';
        pre[p] = cur[x];
        cur[x] = p;
    }

    for(int p = 1; p <= n; p++) {
        dp[p][0] = 1;
        for(int sz = 1; sz <= n; sz++) {
            dp[p][sz] = (dp[p - 1][sz] + dp[p - 1][sz - 1]);
            if(pre[p])
                dp[p][sz] -= dp[pre[p] - 1][sz - 1];
            if(dp[p][sz] > INF)
                dp[p][sz] = INF;
            //cout << "dp(" << p << ", " << sz << ") = " << dp[p][sz] << '\n';
        }
    }

    ll ans = 0;
    for(int sz = n; sz >= 0; sz--) {
        if(k == 0)
            break;
        if(dp[n][sz] >= k) {
            ans += k * ((ll)(n - sz));
            k = 0;
        }
        else {
            ans += dp[n][sz] * ((ll)(n - sz));
            k -= dp[n][sz];
        }
    }
    if(k)
        cout << "-1\n";
    else
        cout << ans << '\n';
}