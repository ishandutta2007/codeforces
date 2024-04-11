#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

const ll MOD = (119 << 23) + 1, gen = 62;

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k <<= 1) {
        if(k & e) res = (res * b)%MOD;
        b = (b * b)%MOD;
    }
    return res;
}

void ntt(vl &f, vl &root, vector<int> &rev) {
    int n = f.size();
    for(int i = 0; i < n; i++)
        if(i < rev[i]) swap(f[i], f[rev[i]]);
    for(int k = 1; k < n; k *= 2) {
        for(int i = 0; i < n; i += 2*k) {
            for(int j = 0; j < k; j++) {
                ll z = (root[j + k] * f[i + j + k]) % MOD;
                f[i + j + k] = (f[i + j] < z ? f[i + j] - z + MOD : f[i + j] - z);
                f[i + j] = (f[i + j] + z >= MOD ? f[i + j] + z - MOD : f[i + j] + z);
            }
        }
    }
}

vl conv(vl A, vl B) {
    int sz = A.size() + B.size() - 1, L = 32 - __builtin_clz(sz), n = 1 << L;
    vl f(A), g(B), res(n), root(n, 1);
    f.resize(n), g.resize(n);
    ll pr = mpow(gen, (MOD - 1)/n), inv = mpow(n, MOD - 2);
    for(int i = n/2 + 1; i < n; i++)
        root[i] = (pr * root[i - 1])%MOD;
    for(int i = n/2 - 1; i >= 0; i--)
        root[i] = root[2*i];
    vector<int> rev(n);
    for(int i = 1; i < n; i++)
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (L - 1));
    ntt(f, root, rev), ntt(g, root, rev);
    for(int i = 0; i < n; i++)
        res[i] = (f[i] * g[i])%MOD;
    reverse(res.begin() + 1, res.end());
    ntt(res, root, rev);
    for(int i = 0; i < sz; i++)
        res[i] = (res[i] * inv) % MOD;
    return {res.begin(), res.begin() + sz};
}

int main() {
    vl p(10);
    int n, k;
    cin >> n >> k;
    while(k--) {
        int d;
        cin >> d;
        p[d]++;
    }
    vl res = {1};
    for(int z = 1; z <= n/2; z *= 2) {
        if(z & (n/2)) res = conv(res, p);
        p = conv(p, p);
    }
    ll ans = 0;
    for(auto x : res)
        ans = (ans + x * x)%MOD;
    cout << endl;
    cout << ans << '\n';
}