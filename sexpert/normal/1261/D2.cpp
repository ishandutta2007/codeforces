#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const ll i2 = (MOD + 1)/2;
const int MAXN = 2e5 + 5;
ll pk[MAXN], pk1[MAXN], fac[MAXN], ifac[MAXN];

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll binom(ll n, ll k) {
    if(k > n)
        return 0;
    ll res = (ifac[k] * ifac[n - k]) % MOD;
    res = (res * fac[n]) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    if(k == 1) {
        cout << "0\n";
        return 0;
    }
    pk[0] = pk1[0] = fac[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        pk[i] = (k * pk[i - 1]) % MOD;
        pk1[i] = ((k - 2) * pk1[i - 1]) % MOD;
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    ifac[MAXN - 1] = mpow(fac[MAXN - 1], MOD - 2);
    for(int i = MAXN - 1; i > 0; i--)
        ifac[i - 1] = (ifac[i] * i) % MOD;
    ll tot = 0;
    int eq = 0;
    for(int i = 0; i < n; i++)
        if(v[i] == v[(i + 1) % n])
            eq++;
    int m = n - eq;
    for(int i = 0; 2*i <= m; i++) {
        ll res = (binom(m, i) * binom(m - i, i)) % MOD;
        res = (res * pk1[m - 2*i]) % MOD;
        tot += res;
        if(tot > MOD)
            tot -= MOD;
    }
    tot = (tot * pk[eq]) % MOD;
    ll ans = ((pk[n] - tot) * i2) % MOD;
    cout << (ans + MOD) % MOD << '\n';
}