#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;
    vector<array<int, 3>> v(m);
    for(int i = 0; i < m; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    ll ways = 1;
    for(int bit = 0; bit < k; bit++) {
        vector<int> a(n + 2), le(n + 1);
        vector<ll> dp(n + 1), su(n + 1);
        for(auto s : v) {
            int ty = (s[2] & (1 << bit)) >> bit;
            if(ty == 0)
                le[s[1]] = max(le[s[1]], s[0]);
            else {
                a[s[0]]++;
                a[s[1] + 1]--;
            }
        }
        for(int i = 1; i <= n; i++)
            a[i] += a[i - 1];
        for(int i = 1; i <= n; i++)
            a[i] = min(a[i], 1);
        dp[0] = su[0] = 1;
        int l = 0;
        for(int i = 1; i <= n; i++) {
            su[i] = su[i - 1];
            if(a[i] == 0) {
                dp[i] = su[i - 1] - (l ? su[l - 1] : 0);
                dp[i] %= MOD;
                if(dp[i] < 0)
                    dp[i] += MOD;
                su[i] += dp[i];
                su[i] %= MOD;
            }
            l = max(l, le[i]);
        }
        ll cur = 0;
        for(int i = l; i <= n; i++) {
            cur += dp[i];
            if(cur >= MOD)
                cur -= MOD;
        }
        ways = (ways * cur) % MOD;
    }
    cout << ways << '\n';
}