#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 15e4 + 10;
const ll MOD = 998244353;

int ti, n, q, sz[MAXN], par[MAXN], nxt[MAXN], tin[MAXN], tout[MAXN];
vector<int> adj[MAXN];
ll BIT[MAXN], tag[MAXN];

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

void upd(int p, ll v) {
    for(; p < MAXN; p += (p & -p)) BIT[p] += v;
}

ll sum(int p) {
    ll res = 0;
    for(; p; p -= (p & -p)) res += BIT[p];
    return res;
}

void add(int L, int R, ll v) {
    upd(L, v);
    upd(R + 1, -v);
}

void dfs_sz(int s, int p = 0) {
    par[s] = p;
    sz[s] = 1;
    for(auto &v : adj[s])
        if(v == p) swap(v, adj[s][adj[s].size() - 1]);
    for(auto &v : adj[s]) {
        if(v == p)
            continue;
        dfs_sz(v, s);
        sz[s] += sz[v];
        if(sz[v] > sz[adj[s][0]])
            swap(adj[s][0], v);
    }
}

void dfs_hld(int s, int p = 0) {
    tin[s] = ti++;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        nxt[v] = (v == adj[s][0] ? nxt[s] : v);
        dfs_hld(v, s);
    }
    tout[s] = ti;
}

int main() {
    ios_base::sync_with_stdio(false),
    cin.tie(0);
    
    cin >> n >> q;
    ll ivn = mpow(n, MOD - 2);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_sz(1);
    ti = 1;
    dfs_hld(1);
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int v;
            ll d;
            cin >> v >> d;
            add(tin[v], tin[v], d * n);
            add(1, n, d * sz[v]);
            add(tin[v], tout[v] - 1, -d * sz[v]);
            tag[v] += d;
            if(adj[v].size() && adj[v][0] != par[v]) {
                int u = adj[v][0];
                add(tin[u], tout[u] - 1, d * (n - sz[u]));
            }
        }
        else {
            int v;
            cin >> v;
            ll ans = sum(tin[v]);
            int u = v;
            while(nxt[u] > 0) {
                u = nxt[u];
                ans += tag[par[u]] * (n - sz[u]);
                u = par[u];
            }
            cout << ((ans % MOD) * ivn) % MOD << '\n';
        }
    }
}