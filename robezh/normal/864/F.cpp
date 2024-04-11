#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 3005, Q = (int)4e5 + 50, INF = (int)1e9;

struct edge {
    int a, b;
} es[N];


int n, m;
vi G[N];
int good[N], to[N], vis[N];
vector<pii> qrs[N][N];
int res[Q];

void dfs(int v) {
    good[v] = 1;
    for (int nxt : G[v]) if(!good[nxt]) dfs(nxt);
}

void build_good(int v) {
    memset(good, 0, sizeof(good));
    rep(i, 0, n) G[i].clear();
    rep(i, 0, m) G[es[i].b].push_back(es[i].a);
    dfs(v);
}

int S[N], sz = 0;

void solve(int v, int rt) {
    S[sz++] = v;
    for(auto &p : qrs[v][rt]) {
        if(sz >= p.first) res[p.second] = S[sz - p.first];
    }

    for (int nxt : G[v]) {
        solve(nxt, rt);
    }
    sz--;
}

void build_tree(int v) {
    rep(i, 0, n) G[i].clear();
    fill(to, to + n, INF);
    rep(i, 0, m) {
        if(es[i].a != v && good[es[i].a] && good[es[i].b]) to[es[i].a] = min(to[es[i].a], es[i].b);
    }
    rep(i, 0, n) {
        if(to[i] != INF) G[to[i]].push_back(i);
    }
    memset(vis, 0, sizeof(vis));
    solve(v, v);
}

int q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        es[i] = {a, b};
    }
    memset(res, -1, sizeof(res));
    rep(i, 0, q) {
        int s, t, k; cin >> s >> t >> k; s--, t--;
        qrs[s][t].push_back({k, i});
    }
    rep(i, 0, n) {
        build_good(i);
        build_tree(i);
    }
    rep(i, 0, q) cout << (res[i] == -1 ? -1 : res[i] + 1) << '\n';
}