#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int MAXL = 23;
const long long INF = 1e10;
int h[MAXN], parent[MAXN][MAXL], pardsu[MAXN], val[MAXN], root;
long long tot = 0, added = 0;
vector<int> adj[MAXN];

struct edge {
    int u, v, wt;
    edge(int u = 0, int v = 0, int wt = 0) : u(u), v(v), wt(wt){}
};

vector<edge> edges;
vector<edge> badEdges;
set<pair<int, int>> ownEdges;

void init() {
    for(int i = 0; i < MAXN; i++)
        pardsu[i] = 0;
}

int find(int x) {
    return (pardsu[x] == 0) ? x : pardsu[x] = find(pardsu[x]);
}

void join(int x, int y) {
    int a = find(x), b = find(y);
    if(h[a] > h[b])
        swap(a, b);
    if(a != b) {
        pardsu[b] = a;
    }
}

void kruskal() {
    init();
    for(edge e : edges) {
        if(find(e.u) != find(e.v)) {
            join(e.u, e.v);
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);
        }
        else
            badEdges.push_back(e);
    }
}

void dfs(int s, int p = -1) {
    h[s] = (p == -1 ? 0 : h[p] + 1);
    parent[s][0] = (p == -1 ? 0 : p);
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
    }
}

void buildLCA() {
    dfs(root);
    for(int i = 1; i < MAXL; i++) {
        for(int v = 1; v < MAXN; v++) {
            if(parent[v][i - 1] != 0) {
                parent[v][i] = parent[parent[v][i - 1]][i - 1];
            }
        }
    }
}

int LCA(int u, int v) {
    if(h[u] > h[v])
        swap(u, v);
    int diff = h[v] - h[u];
    for(int i = MAXL - 1; i >= 0; i--) {
        if(diff >= (1 << i)) {
            v = parent[v][i];
            diff -= (1 << i);
        }
    }
    if(u == v)
        return u;
    for(int i = MAXL - 1; i >= 0; i--) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

void query(int u, int v, long long w) {
    u = find(u);
    v = find(v);
    while(u != v) {
        int x = parent[u][0];
        //cout << u << " " << x << " " << v << endl;
        if(ownEdges.find(make_pair(min(x, u), max(x, u))) != ownEdges.end()) {
            added++;
            tot += w;
        }
        join(u, x);
        u = find(x);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long n, k, m;
    cin >> n >> k >> m;
    for(int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        edge e = edge(u, v, 0);
        ownEdges.insert({min(u, v), max(u, v)});
        edges.push_back(e);
        long long x = min(u, v), y = max(u, v);
    }
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge e = edge(u, v, w);
        edges.push_back(e);
    }
    kruskal();
    root = edges[0].u;
    buildLCA();
    init();
    for(edge e : badEdges) {
        int l = LCA(e.u, e.v);
        query(e.u, l, e.wt);
        query(e.v, l, e.wt);
    }
    if(added < ownEdges.size())
        cout << -1 << endl;
    else
        cout << tot << endl;
}