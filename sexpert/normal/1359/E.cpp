#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 10;
ll fac[MAXN];
ll ifac[MAXN];
const ll MOD = 998244353;

ll inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll binom(ll n, ll k) {
    if(k < 0 || k > n)
        return 0;
    ll res = (ifac[k] * ifac[n - k]) % MOD;
    res = (res * fac[n]) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    
    fac[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
    ifac[MAXN - 1] = inv(fac[MAXN - 1]);
    for(int i = MAXN - 1; i > 0; i--)
        ifac[i - 1] = (ifac[i] * i) % MOD;
        
    ll ans = 0;
    for(ll g = 1; g <= n; g++) {
        ll amt = n/g;
        ans = (ans + binom(amt - 1, k - 1)) % MOD;
    }
    cout << ans << '\n';
}