#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


const int N = (int)2e5 + 50;
const int INF = (int)1e9;


struct edge{
    int to, cap, rev, id;
    edge(int _to, int _cap, int _rev, int _id){
        to = _to, cap = _cap, rev = _rev, id = _id;
    }
};

struct Dinic {
    vector<edge> G[N];
    int level[N], iter[N];

    void add_edge(int from, int to, int cap, int id){
        G[from].push_back(edge(to, cap, G[to].size(), id));
        G[to].push_back(edge(from, 0, G[from].size() - 1, id));
    }

    void bfs(int s){
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int i = 0; i < G[v].size(); i++){
                edge &e = G[v][i];
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }


    int dfs(int v, int t, int f){
        if(v == t) return f;

        for(int &i = iter[v]; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                int d = dfs(e.to, t, min(e.cap, f));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }


    int max_flow(int s, int t){
        int flow = 0;
        for(;;){
            bfs(s);
            if(level[t] < 0) return flow;
            memset(iter, 0, sizeof(iter));
            int f;
            while((f = dfs(s, t, INF)) > 0){
                flow += f;
            }
        }
    }
} dinic;

struct DSU {
    int f[N];
//    int cnt;
//    int _n;

    void init(int n) {
//        cnt = n = _n;
        iota(f, f + n, 0);
    }
    int find(int u) {return f[u] == u ? u : f[u] = find(f[u]);}
    void unite(int u, int v) {
//        cout << u << " " << v << endl;
        assert(find(u) != find(v));
//        cnt--;
        f[find(u)] = find(v);
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
//    void add_edge(int lim) {
//        rep(i, 1, _n) {
//            if(cnt > lim && find(i) != find(0)) {
//                unite(i, 0);
//            }
//        }
//    }
} dsu[2];

int n, m[2];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m[0] >> m[1];
    rep(b, 0, 2) {
        dsu[b].init(n);
        rep(i, 0, m[b]) {
            int u, v; cin >> u >> v; u--, v--;
            dsu[b].unite(u, v);
        }
    }
//    dsu[0].add_edge(dsu[1].cnt);
//    dsu[1].add_edge(dsu[0].cnt);
    vector<pii> res;
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            if(!dsu[0].same(i, j) && !dsu[1].same(i, j)) {
                dsu[0].unite(i, j);
                dsu[1].unite(i, j);
                res.push_back({i, j});
            }
        }
    }
    cout << sz(res) << endl;
    for (auto p : res) cout << p.first + 1 << " " << p.second + 1 << '\n';



}