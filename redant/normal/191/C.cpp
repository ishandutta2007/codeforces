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
    };

    vector<Edge> edges;
    vector<vector<int> > g;
    vector<int> par;
    vector<int> depth;
    vector<int> val;
    int n;

    vector<vector<int> > ppar;
    int root;
    int K;
    

    Tree(int _n) : n(_n) {
        edges.clear(); 
        g.resize(n);
        val.resize(n);
    }

    void addEdge(int from, int to) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = edges.size();
        edges.push_back({from, to});
        g[from].push_back(id);
        g[to].push_back(id);
    }

    void buildRoot(int _root) {
        root = _root;
        par.resize(n, 0);
        depth.resize(n, 0);
        build(root, root, 0);
        buildPar2pow();
    }

    void build(int u, int pu, int d) {
        par[u] = pu;
        depth[u] = d;
        for (auto &id : g[u]) {
            int v = edges[id].from;
            if (v == u) v = edges[id].to;
            if (v != pu)
                build(v, u, d+1);
        }
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

    void goFools(int u, int v) {
        val[u]++; val[v]++;
        int lca = findLCA(u, v);
        val[lca] -= 2;
    }

    void solve(vector<int> &ans) {
        solve(0, -1, ans);
    }

    int solve(int u, int pu, vector<int> &ans) {
        int sum = val[u];
        for (auto &id : g[u]) {
            int v = edges[id].from;
            if (v == u) v = edges[id].to;
            if (v != pu)
                sum += ans[id] = solve(v, u, ans);
        }
        return sum;
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
        tree.goFools(u-1, v-1);
    }

    vector<int> ans(n-1);
    tree.solve(ans);

    REP(i, ans.size())
        cout << ans[i] << " ";
    cout << endl;
}

int main() {
    setIO();
    solve();
    return 0;
}