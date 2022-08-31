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
        int countDown;
    };

    vector<Edge> edges;
    vector<vector<int> > g;
    vector<int> par;
    vector<int> parEdgeId;
    vector<int> depth;
    vector<int> fullCount;
    int n;

    vector<vector<int> > ppar;
    int root;
    int K;
    

    Tree(int _n) : n(_n) {
        edges.clear(); 
        g.resize(n);
    }

    void addEdge(int from, int to) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = edges.size();
        edges.push_back({from, to, 0});
        g[from].push_back(id);
        g[to].push_back(id);
    }

    void buildRoot(int _root) {
        root = _root;
        par.resize(n, 0);
        depth.resize(n, 0);
        fullCount.resize(n, 0);
        parEdgeId.resize(n, -1);
        build(root, root, 0);
        buildPar2pow();
    }

    int build(int u, int pu, int d) {
        par[u] = pu;
        depth[u] = d;
        int sum = 1;
        for (auto &id : g[u]) {
            int v = edges[id].from;
            if (v == u) v = edges[id].to;
            if (v == pu) {
                parEdgeId[u] = id;
            } else {
                int count = build(v, u, d+1);
                edges[id].countDown = count;
                sum += count;
            }
        }
        return fullCount[u] = sum;
    }

    void buildPar2pow() {
        K = 1;
        while (1 << K < n) ++K;
        ppar.resize(n, vector<int>(K+1, 0));
        for (int u = 0; u < n; u++) {
            ppar[u][0] = par[u];
        }
        for (int k = 1; k <= K; k++) {
            for (int u = 0; u < n; u++) {
                int v = ppar[u][k-1];
                ppar[u][k] = ppar[v][k-1];
            }
        }
    }

    int findLCA(int u, int v) {
        if (depth[u] > depth[v])
            swap(u, v);

        for (int d = depth[v] - depth[u], k = 0; d > 0; d >>= 1, ++k)
            if (d&1) {
                v = ppar[v][k];
            }
        for (int k = K; k >= 0; --k) {
            if (ppar[u][k] != ppar[v][k]) {
                u = ppar[u][k];
                v = ppar[v][k];
            }
        }
        return u == v ? u : par[u];
    }

    int jumpAndGet(int v, int d) {
        for (int dd = d - 1, k = 0; dd > 0; dd >>= 1, ++k)
            if (dd&1) {
                v = ppar[v][k];
            }
        int res = fullCount[par[v]] - edges[parEdgeId[v]].countDown;
        // cout << "jg " << v << ", " << d << ", " << res << endl;
        // cout << fullCount[par[v]] << endl;
        int id = parEdgeId[v];
        // cout << "id = " << id << ": " << edges[id].from << edges[id].to << edges[id].countDown << endl;
        // cout << edges[parEdgeId[v]].countDown << endl;
        return res;
    }

    int solve(int a, int b) {
        if (a == b) return n;
        if (depth[a] == depth[b]) {
            int u = a, v = b;
            for (int k = K; k >= 0; --k) {
                if (ppar[u][k] != ppar[v][k]) {
                    u = ppar[u][k];
                    v = ppar[v][k];
                }
            }
            return n - edges[parEdgeId[u]].countDown - edges[parEdgeId[v]].countDown;
        }

        if (depth[a] > depth[b])
            swap(a, b);

        int u = a, v = b;
        int d = depth[b] - depth[a];
        for (int dd = d, k = 0; dd > 0; dd >>= 1, ++k)
            if (dd&1) {
                v = ppar[v][k];
            }

        if (u == v) {
            return d&1 ? 0 : jumpAndGet(b, d/2);
        }

        int lca = findLCA(u, v);
        int td = 2 * (depth[u] - depth[lca]) + d;
        return td&1 ? 0 : jumpAndGet(b, td/2);
    }

};

void solve() {
    int n;
    cin >> n;
    Tree<LL> tree(n);

    REP(i, n-1) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u-1, v-1);
    }
    tree.buildRoot(0);

    int k;
    cin >> k;
    while(k--) {
        int u, v;
        cin >> u >> v;
        cout << tree.solve(u-1, v-1) << "\n";
    }
}

int main() {
    setIO();
    solve();
    return 0;
}