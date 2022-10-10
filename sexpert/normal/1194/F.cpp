#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
ll fac[MAXN], ifac[MAXN];

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k <<= 1) {
        if(e & k) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll inv(ll b) { return mpow(b, MOD - 2); }

ll binom(ll n, ll k) {
    ll res = fac[n];
    res = (res * ifac[k]) % MOD;
    res = (res * ifac[n - k])%MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(ll i = 1; i < MAXN; i++)
        fac[i] = (i * fac[i - 1])%MOD;
    ifac[MAXN - 1] = inv(fac[MAXN - 1]);
    for(ll i = MAXN - 1; i > 0; i--)
        ifac[i - 1] = (i * ifac[i]) % MOD;

    int n;
    ll T;
    cin >> n >> T;
    vector<ll> v(n), pf(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        pf[i + 1] = pf[i] + v[i];
    }
    //for(auto x : pf)
    //    cout << x << " ";
    //cout << endl;
    ll ans = 0;
    for(int m = 0; m <= n; m++) {
        if(pf[m] > T)
            break;
        if(m < n && pf[m + 1] + m + 1 <= T)
            continue;
        //cout << m << endl;
        //pf[m + 1] + k + 1 > T
        ll k = 0;
        if(m < n)
            k = max(0LL, T - pf[m + 1]);
        for(; k <= m && pf[m] + k <= T; k++) {
            //cout << k << " ";
            ll tmp = (binom(m, k) * inv(mpow(2, m))) % MOD;
            tmp = (tmp * m) % MOD;
            if(m < n && pf[m + 1] + k <= T) {
                //cout << "oops ";
                tmp = (tmp * inv(2)) % MOD;
            }
            ans = (ans + tmp) % MOD;
        }
        //cout << endl;
    }
    cout << ans << '\n';
}