#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;
const ll mod = 1e9 + 7;
int pos[MAXN], sa[MAXN], n, k;
 
ll fac[MAXN], ifac[MAXN];
 
ll binom(ll n, ll k) {
    if(k < 0 || k > n)
        return 0;
    ll res = (fac[n] * ifac[k]) % mod;
    return (res * ifac[n - k]) % mod;
}
 
ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    // m lights
    ll ans = 2;
    ll bad = (n * (n - 1)) % mod;
    for(int m = 2; m <= n; m++) {
        ll tmp = binom(n - m * k + m + k - 1, m);
        tmp = (tmp * fac[m]) % mod;
        tmp = (tmp * modpow(bad, mod - 2)) % mod;
        ans = (ans + tmp) % mod;
        bad = (bad * (n - m)) % mod;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(ll k = 1; k < MAXN; k++)
        fac[k] = (k * fac[k - 1]) % mod;
 
    ifac[MAXN - 1] = modpow(fac[MAXN - 1], mod - 2);
    for(ll i = MAXN - 1; i >= 1; i--)
        ifac[i - 1] = (i * ifac[i]) % mod;

    int t;
    cin >> t;
    while(t--)
        solve();
}