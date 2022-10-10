#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

const int MAXN = 5005;
ll dp[MAXN][MAXN];
ll tot[MAXN];
ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    
    for(int i = 1; i <= n; i++)
        dp[0][i] = 1;

    for(int j = 1; j <= k; j++) {
        for(int i = 1; i <= n; i++)
            dp[j][i] = (dp[j - 1][i - 1] + dp[j - 1][i + 1]) % MOD;
    }

    //for(int j = 0; j <= k; j++) {
    //    for(int i = 1; i <= n; i++) {
    //        cout << dp[j][i] << " ";
    //    }
    //    cout << '\n';
    //}

    for(int i = 1; i <= n; i++) {
        tot[i] = (2LL * dp[k][i]) % MOD;
        for(int ps = 2; ps <= k; ps++) {
            ll le = (dp[ps - 2][i - 1] + dp[ps - 2][i + 1]) % MOD;
            ll ri = (dp[k - ps][i - 1] + dp[k - ps][i + 1]) % MOD;
            tot[i] = (tot[i] + le * ri) % MOD;
        }
    }

    //for(int i = 1; i <= n; i++) {
    //    cout << tot[i] << " ";
    //
    //}
    //cout << '\n';

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = (ans + a[i] * tot[i]) % MOD;
    }

    //cout << ans << '\n';

    for(int i = 0; i < q; i++) {
        int idx;
        ll x;
        cin >> idx >> x;
        ans -= (a[idx] * tot[idx]);
        ans %= MOD;
        a[idx] = x;
        ans += (a[idx] * tot[idx]);
        ans %= MOD;

        cout << (ans + MOD)%MOD << '\n';
    }
}