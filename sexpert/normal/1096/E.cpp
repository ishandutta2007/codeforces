#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MAXN = 5555;
ll fac[MAXN], ifac[MAXN];

ll binom(ll n, ll k) {
    if(k > n || k < 0)
        return 0;
    ll ans = (ifac[k] * ifac[n - k]) % MOD;
    return (ans * fac[n]) % MOD;
}

ll inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll awoo(ll p, ll ts, ll bn) {
    if(p == 0) {
        if(ts == 0)
            return 1;
        else
            return 0;
    }
    ll res = 0;
    for(ll meanies = 0; meanies * bn <= ts; meanies++) {
        if(meanies > p)
            break;
        ll cnt = (binom(p, meanies) * binom(ts - meanies * bn + p - 1, p - 1)) % MOD;
        if(meanies % 2)
            res = (res - cnt) % MOD;
        else
            res = (res + cnt) % MOD;
    }
    return (res + MOD) % MOD;
}

int main() {
    fac[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fac[i] = (i * fac[i - 1]) % MOD;
    ifac[MAXN - 1] = inv(fac[MAXN - 1]);
    for(int i = MAXN - 1; i >= 1; i--)
        ifac[i - 1] = (i * ifac[i]) % MOD;

    ll p, s, r, ans = 0, ways = 0;
    cin >> p >> s >> r;
    if(p == 1) {
        cout << "1\n";
        return 0;
    }
    if(r == 0) {
        cout << inv(p) << '\n';
        return 0;
    }
    for(ll sc = r; sc <= s; sc++) {
        ways = (ways + binom(s - sc + p - 2, p - 2)) % MOD;
        for(ll np = 1; np * sc <= s; np++) {
            if(np > p)
                break;
            ll res = (awoo(p - np, s - np * sc, sc) * inv(np)) % MOD;
            res = (res * binom(p - 1, np - 1)) % MOD;
            ans += res;
            if(ans >= MOD)
                ans -= MOD;
        }
    }
    cout << (ans * inv(ways)) % MOD << '\n';
}