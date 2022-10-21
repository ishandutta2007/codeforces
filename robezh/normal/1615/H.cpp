#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> P;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = (int)1e9 + 50;

struct edge{
    int to, cap, rev, id;
    edge(int _to, int _cap, int _rev, int _id){
        to = _to, cap = _cap, rev = _rev, id = _id;
    }
};


struct Dinic {
    vector<vector<edge>> G;
    vi level, iter;

    Dinic(int n) : G(n), level(n), iter(n) {}

    void add_edge(int from, int to, int cap, int id) {
        G[from].push_back(edge(to, cap, G[to].size(), id));
        G[to].push_back(edge(from, 0, G[from].size() - 1, id));
    }

    void bfs(int s) {
        fill(all(level), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }


    int dfs(int v, int t, int f) {
        if (v == t) return f;

        for (int &i = iter[v]; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(e.cap, f));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }


    int max_flow(int s, int t) {
        int flow = 0;
        for (;;) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(all(iter), 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
    }

    vi find_cut_s(int s) {
        vi vis(sz(G), 0);
        vi res;
        function<void(int)> find = [&](int v) {
            vis[v] = 1;
            res.push_back(v);
            for (auto &e : G[v]) if(e.cap && !vis[e.to]) find(e.to);
        };
        find(s);
        return res;
    }
};

const int N = 1005;

int n, m;
int a[N];
vi G[N];
int in[N], id[N];
int res[N];

void solve(int l, int r, vi &S) {
    for (int i = 0; i < sz(S); i++) id[S[i]] = i;
    if(S.empty()) return ;
    if(l == r) {
        for (int x : S) res[x] = l;
        return ;
    }

    int mid = (l + r) / 2 + 1;
    Dinic flow(sz(S) + 2);
    int s = sz(S), t = s + 1;

    for (int x : S) in[x] = 1;
    for (int v : S) {
        for (int u : G[v]) if(in[u]) flow.add_edge(id[v], id[u], INF, -1);
    }
    for (int x : S) in[x] = 0;

    rep(j, 0, sz(S)) {
        int i = S[j];
        if (a[i] <= mid - 1) flow.add_edge(s, j, 1, i);
        else flow.add_edge(j, t, 1, i);
    }

    flow.max_flow(s, t);
    vi cut = flow.find_cut_s(s);
    for (int v : cut) {
        if(v == s) continue;
        in[v] = 1;
    }

    vi L, R;
    for (int x : S) (in[id[x]] ? L : R).push_back(x);
    for (int x : S) in[id[x]] = 0;


    if(l + 1 == r) {
        for (int x : L) res[x] = l;
        for (int x : R) res[x] = r;
        return ;
    }

    solve(l, mid - 1, L);
    solve(mid, r, R);

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        G[v].push_back(u);
    }
    vi idx(n, 0);
    iota(all(idx), 0);
    solve(1, (int)1e9, idx);
    rep(i, 0, n) cout << res[i] << " ";
    cout << '\n';
}