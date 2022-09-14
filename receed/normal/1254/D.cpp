#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 150004, MOD = 998244353;
vector<int> g[N];
int tin[N], tout[N], ct, par[N], hn[N], ho[N], hp[N], cn;
ll w[N], f[N], sz[N];

ll xy;
ll addm(ll x, ll y) {
    xy = x + y;
    return xy >= MOD ? xy - MOD : xy;
}

void add(int p, ll x) {
    for (int i = p; i < N; i |= (i + 1))
        f[i] = addm(f[i], x);
}

ll sum(int p) {
    ll res = 0;
    for (int i = p; i; i &= (i - 1))
        res = addm(res, f[i - 1]);
    return res;
}
ll sum(int l, int r) {
    return (sum(r) - sum(l) + MOD) % MOD;
}

ll pw(ll x, ll k) {
    ll res = 1;
    for (int i = 30; i >= 0; i--) {
        res = res * res % MOD;
        if (k & (1 << i))
            res = res * x % MOD;
    }
    return res;
}

void dfs(int v, int p) {
    par[v] = p;
    tin[v] = ct++;
    sz[v] = 1;
    for (int u : g[v])
        if (u != p) {
            dfs(u, v);
            sz[v] += sz[u];
        }
    tout[v] = ct;
}

void build(int v, int p) {
    hn[v] = cn;
    ho[cn] = v;
    cn++;
    int mv = -1;
    for (int u : g[v]) {
        if (u == p)
            continue;
        if (mv == -1 || g[u].size() > g[mv].size())
            mv = u;
    }
    if (mv == -1)
        return;
    hp[mv] = hp[v];
    build(mv, v);
    for (int u : g[v])
        if (u != p && u != mv) {
            hp[u] = u;
            build(u, v);
        }
}

    
int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, q, u, v, t, d;
    cin >> n >> q;
    rep(i, n - 1) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    hp[1] = 1;
    dfs(1, -1);
    build(1, -1);
    ll rn = pw(n, MOD - 2), ts = 0;
    rep(z, q) {
        cin >> t >> v;
        if (t == 1) {
            cin >> d;
            w[v] = addm(w[v], d);
            ll x = d * sz[v] % MOD;
            ts = addm(ts, x);
            add(hn[v], (MOD - x) % MOD);
            u = ho[hn[v] + 1];
            if (par[u] == v)
                add(hn[v] + 1, (n - sz[u]) * d % MOD);
        }
        else {
            ll ans = (ts + w[v] * n) % MOD;
            while (1) {
                int nv = hp[v];
                ans = addm(ans, sum(hn[nv], hn[v] + 1));
                if (nv == 1)
                    break;
                ans = addm(ans, w[par[nv]] * (n - sz[nv]) % MOD);
                v = par[nv];
            }
            cout << ans * rn % MOD << '\n';
        }
    }
}