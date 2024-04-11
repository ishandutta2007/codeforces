#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1003 + 50, M = (int)3e4 + 50, INF = (int)2e9 + 50;

struct edge {
    int to, id, cost;
};

struct ed {
    int u, v, cost;
};

int n, m, s, t;
vector<edge> G[N];
ed es[M];
int vis[N];
vi path;
int pre[N], low[N], cnt;
ll best = INF;
vector<int> res;

int span(int v) {
    vis[v] = 1;
    if(v == t) return 1;
    for(auto e : G[v]) {
        if(!vis[e.to] && span(e.to)) {
            path.push_back(e.id);
            return 1;
        }
    }
    return 0;
}

pii solve(int ig = -1) {
    pii res = {INF, INF};
    function<int(int, int)> dfs = [&](int v, int id) {
        pre[v] = low[v] = ++cnt;
        int has_t = (v == t);

        for(auto e : G[v]) {
            if(e.id == id) continue;
            if(pre[e.to] == 0) {
                has_t |= dfs(e.to, e.id);
                low[v] = min(low[v], low[e.to]);
            }
            else low[v] = min(low[v], pre[e.to]);
        }

        if(pre[v] == low[v] && id != -1 && has_t) {
            res = min(res, {es[id].cost, id});
        }
        return has_t;
    };
    fill(pre, pre + n, 0);
    fill(low, low + n, 0);
    cnt = 0;
    rep(j, 0, n) G[j].clear();
    rep(j, 0, m) {
        if(j != ig) {
            G[es[j].u].push_back({es[j].v, j, es[j].cost});
            G[es[j].v].push_back({es[j].u, j, es[j].cost});
        }
    }
    dfs(s, -1);
    return res;
}

int main() {
    cin >> n >> m >> s >> t;
    s--, t--;
    rep(i, 0, m) {
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        if(a == b) continue;
        G[a].push_back({b, i, w});
        G[b].push_back({a, i, w});
        es[i] = {a, b, w};
    }
    span(s);
    if(path.empty()) {
        cout << "0\n0\n";
        return 0;
    }
//    for(int p : path) cout << p + 1 << " ";
//    cout << endl;
    pii sig = solve();
    if(sig.first != INF) {
        best = sig.first;
        res = {sig.second};
    }
    for(int i : path) {
        pii db = solve(i);
        if(1LL * db.first + es[i].cost < best) {
            best = 1LL * db.first + es[i].cost;
            res = {db.second, i};
        }
    }
    if(best == INF) return cout << -1 << endl, 0;
    cout << best << '\n';
    cout << sz(res) << '\n';
    for(int x : res) cout << x + 1 << " ";
    cout << '\n';

}