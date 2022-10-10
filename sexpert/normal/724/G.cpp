#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
vector<ii> adj[MAXN];
int seen[MAXN], n, m, cs;
ll xo[MAXN], p2[100], ans, cnt[60][2];
vector<ll> basis;
vector<int> comp;

void add(ll x) {
    for(auto b : basis)
        x = min(x, x ^ b);
    if(x == 0)
        return;
    basis.push_back(x);
    sort(basis.rbegin(), basis.rend());
}

void dfs(int s, int p = 0, ll x = 0) {
    for(ll bit = 0; bit < 60; bit++)
        cnt[bit][(x >> bit) & 1]++;
    xo[s] = x;
    seen[s] = 1;
    comp.push_back(s);
    cs++;
    for(auto e : adj[s]) {
        int v = e.first; ll w = e.second;
        if(v == p)
            continue;
        if(seen[v])
            add(xo[v] ^ xo[s] ^ w);
        else
            dfs(v, s, x ^ w);
    }
}

void add(ll &x, ll y) {
    x += y;
    if(x >= MOD)
        x -= MOD;
}

void solve(int rt) {
    basis.clear();
    comp.clear();
    cs = 0;
    memset(cnt, 0, sizeof cnt);
    dfs(rt);
    ll have = 0;
    for(auto b : basis)
        have |= b;
    for(ll bit = 0; bit < 60; bit++) {
        bool flip = false;
        if(have & (1LL << bit))
            flip = true;
        if(flip) {
            ll res = ((ll)cs * (cs - 1))/2;
            res = (res * p2[bit]) % MOD;
            res = (res * p2[basis.size() - 1]) % MOD;
            add(ans, res);
        }
        else {
            //vector<ll> cnt(2);
            //for(auto v : comp)
            //    cnt[(xo[v] >> bit) & 1]++;
            ll res = (cnt[bit][0] * cnt[bit][1]) % MOD;
            res = (res * p2[basis.size()]) % MOD;
            res = (res * p2[bit]) % MOD;
            add(ans, res);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    p2[0] = 1;
    for(int i = 1; i < 100; i++)
        p2[i] = (p2[i - 1] * 2) % MOD;

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i++)
        if(!seen[i])
            solve(i);

    cout << ans << '\n';
}