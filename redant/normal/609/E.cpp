#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

template<typename T>
class Tree {
public:
    struct Edge {
        int from;
        int to;
        T cost;
    };

    vector<vector<Edge> > g;
    vector<int> par;
    int n;

    vector<T> parCost;
    vector<int> depth;
    vector<vector<int> > ppar;
    vector<vector<T> > ccost;
    int root;
    int K;
    

    Tree(int _n) : n(_n) { 
        g.resize(n);
    }

    void addEdge(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        g[from].push_back({from, to, cost});
        g[to].push_back({to, from, cost});
    }

    void buildRoot(int _root) {
        root = _root;
        par.resize(n, 0);
        depth.resize(n, 0);
        parCost.resize(n, 0);
        build(root, root, 0);
        buildPar2pow();
    }

    void build(int u, int pu, int d) {
        par[u] = pu;
        depth[u] = d;
        for (Edge &e : g[u]) {
            if (e.to != pu) {
                parCost[e.to] = e.cost;
                build(e.to, u, d + 1);
            }
        }
    }

    void buildPar2pow() {
        K = 1;
        while (1 << K < n) ++K;
        ppar.resize(n, vector<int>(K+1, 0));
        ccost.resize(n, vector<T>(K+1, 0));
        for (int u = 0; u < n; u++) {
            ppar[u][0] = par[u];
            ccost[u][0] = parCost[u];
        }
        for (int k = 1; k <= K; k++) {
            for (int u = 0; u < n; u++) {
                int v = ppar[u][k-1];
                ppar[u][k] = ppar[v][k-1];
                ccost[u][k] = max(ccost[u][k-1], ccost[v][k-1]);
            }
        }
    }

    T find(int u, int v) {
        if (par[u] == v) {
            return parCost[u];
        } else if (par[v] == u) {
            return parCost[v];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        T res = 0;
        for (int d = depth[v] - depth[u], k = 0; d > 0; d >>= 1, ++k)
            if (d&1) {
                res = max(res, ccost[v][k]);
                v = ppar[v][k];
            }
        
        int distLca = 0;
        if (u != v) {
            int uu = u, vv = v;
            for (int k = K; k >= 0; --k) {
                if (ppar[uu][k] != ppar[vv][k]) {
                    uu = ppar[uu][k];
                    vv = ppar[vv][k];
                    distLca |= 1 << k;
                }
            }
            distLca++;
        }

        for (int d = distLca, k = 0; d > 0; d >>= 1, ++k)
            if (d&1) {
                res = max(res, ccost[v][k]);
                v = ppar[v][k];

                res = max(res, ccost[u][k]);
                u = ppar[u][k];
            }

        return res;
    }

};

template <typename T>
class Graph {
public:
    struct Edge {
        int from;
        int to;
        T cost;
    };

    vector<Edge> edges;
    vector<vector<int> > g;
    int n;

    Graph(int _n) : n(_n) {
        g.resize(n);
    }

    virtual int addEdge(int from, int to, T cost) = 0;
};

template <typename T>
class Undirgraph : public Graph<T> {
public:
    using Graph<T>:: edges;
    using Graph<T>:: g;
    using Graph<T>:: n;

    Undirgraph(int _n): Graph<T>(_n) {}

    int addEdge(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int) edges.size();
        edges.push_back({from, to, cost});
        g[from].push_back(id);
        g[to].push_back(id);
        return id;
    }
};

class DSU {
public:
    vector<int> par;
    int n;

    DSU(int _n): n(_n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }

    inline int find(int u) {
        return u^par[u] ? (par[u] = find(par[u])) : u;
    }

    bool join (int u, int v) {
        if ((u = find(u)) == (v = find(v)))
            return false;
        par[u] = v;
        return true;
    }
};

template<typename T>
T minSpanningTree(const Undirgraph<T> &g, Tree<T> &mst) {
    vector<int> oedges(g.edges.size());
    iota(oedges.begin(), oedges.end(), 0);
    sort(oedges.begin(), oedges.end(), [&g](int a, int b) {
        return g.edges[a].cost < g.edges[b].cost;
    });

    DSU dsu(g.n);
    T ans = 0;
    for (int id : oedges) {
        auto &e = g.edges[id];
        if (dsu.find(e.from) != dsu.find(e.to)) {
            dsu.join(e.from, e.to);
            ans += e.cost;
            mst.addEdge(e.from, e.to, e.cost);
        }
    }
    return ans;
}


void solve() {
    int n, m;
    cin >> n >> m;
    Undirgraph<LL> g(n);

    REP(i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        g.addEdge(u-1, v-1, c);
    }

    Tree<LL> tree(n);
    LL mstw = minSpanningTree(g, tree);
    tree.buildRoot(0);

    for (auto& e : g.edges) {
        cout << mstw - tree.find(e.from, e.to) + e.cost << "\n";
    }
}

int main() {
    setIO();
    solve();
    return 0;
}