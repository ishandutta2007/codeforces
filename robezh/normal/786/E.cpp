#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

const int N = (int)2e4 + 5, INF = (int)1e9;
const int LOGN = 15;
int mm[N];
int root = 0;
int n,m,a,b;


struct edge{
    int to, cap, rev;
    edge(int _to, int _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};

// Finding max flow in O(V^2 * E)
struct Dinic {
    vector<edge> G[N * LOGN];
    int level[N * LOGN], iter[N * LOGN];

    void add_edge(int from, int to, int cap){
//        cout << from << " " << to << " " << cap << endl;
        G[from].push_back(edge(to, cap, G[to].size()));
        G[to].push_back(edge(from, 0, G[from].size() - 1));
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

struct gedge {
    int to, id;
};

int eid[N];

vector<gedge> G[N];
int parent[LOGN][N], gid[LOGN][N];
int gcnt = 0;
int depth[N];
int tin[N], tout[N], tim;
void dfs(int v, int p, int d, int pid){
    parent[0][v] = p;
    depth[v] = d;
    eid[v] = pid;
    tin[v] = tim++;
    for(auto e : G[v]){
        if(e.to != p) dfs(e.to, v, d+1, e.id);
    }
    tout[v] = tim - 1;
}

void init(){
    dfs(root, -1, 0, -1);

    mm[0] = -1;
    for(int i = 1; i <= n; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
    for(int k = 0; k+1 < LOGN; k++){
        for(int v = 0; v < n; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
    rep(k, 0, LOGN) {
        rep(v, 0, n) {
            if(parent[k][v] != -1) {
                gid[k][v] = gcnt++;
                if(k) {
                    dinic.add_edge(gid[k - 1][v], gid[k][v], INF);
                    dinic.add_edge(gid[k - 1][parent[k - 1][v]], gid[k][v], INF);
                }
            }
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOGN; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = LOGN - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int ga(int v, int d) {
    for (int k = 0; k < LOGN; k++) {
        if(d >> k & 1) v = parent[k][v];
    }
    return v;
}

void add(int u, int ca, int idx) {
    if(depth[u] == depth[ca]) return ;
    int d = depth[u] - depth[ca];
    int k = mm[d];
    dinic.add_edge(gid[k][u], idx, INF);
    dinic.add_edge(gid[k][ga(u, d - (1 << k))], idx, INF);
}

void add_path(int u, int v, int idx) {
    int ca = lca(u, v);
    add(u, ca, idx);
    add(v, ca, idx);
}

bool vis[N * LOGN];
vi v0, v1;
int s, t;

void find_cut(int v) {
    vis[v] = true;
    for (auto e : dinic.G[v]) {
        if(e.cap && !vis[e.to]) find_cut(e.to);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    init();
    s = gcnt + m, t = s + 1;
    rep(i, 1, n) dinic.add_edge(s, gid[0][i], 1);
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        add_path(u, v, gcnt + i);
        dinic.add_edge(gcnt + i, t, 1);
    }
    cout << dinic.max_flow(s, t) << '\n';
    find_cut(s);
    rep(i, 0, t + 1) {
        if(!vis[i]) continue;
        for (auto &e : dinic.G[i]) {
            if(!vis[e.to]) {
                if(i == s) {
                    v1.push_back(eid[e.to + 1]);
                } else if(e.to == t) {
//                    assert(e.to == t);
                    v0.push_back(i - gcnt);
                }
            }
        }
    }
    cout << sz(v0) << " ";
    for (int x : v0) cout << x + 1 << " ";
    cout << '\n';
    cout << sz(v1) << " ";
    for (int x : v1) cout << x + 1 << " ";
    cout << '\n';
}