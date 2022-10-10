#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k <<= 1) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll inv(ll b) {
    return mpow(b, MOD - 2);
}

int prime[MAXN], m;
ll f[MAXN];

void sieve() {
    for(int p = 2; p < MAXN; p++) {
        if(!prime[p])
            for(int q = p; q < MAXN; q += p)
                prime[q] = p;
    }
}

ll c(int a, int d) {
    int b = a / d, res = 0;
    vector<int> pf;
    while(b > 1) {
        int p = prime[b];
        pf.push_back(p);
        while(b % p == 0) b /= p;
    }
    for(int i = 0; i < (1 << pf.size()); i++) {
        int prod = 1;
        for(int j = 0; j < pf.size(); j++)
            if((1 << j) & i) prod *= pf[j];
        if(__builtin_popcount(i) % 2)
            res -= m / (d * prod);
        else
            res += m / (d * prod);
    }
    return res;
}

int main() {
    cin >> m;
    sieve();
    for(int n = 2; n <= m; n++) {
        ll tot = m;
        for(int d = 2; d * d <= n; d++) {
            if(n % d) continue;
            tot = (tot + f[d] * c(n, d)) % MOD;
            if(n / d > d)
                tot = (tot + f[n / d] * c(n, n / d))%MOD;
        }
        f[n] = (tot * inv(m - c(n, n))) % MOD;
    }
    ll ans = 0;
    for(int n = 1; n <= m; n++)
        ans = (ans + f[n]) % MOD;
    ans = (ans * inv(m) + 1) % MOD;
    if(ans < 0) ans += MOD;
    cout << ans << '\n';
}