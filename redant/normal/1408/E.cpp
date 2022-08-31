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
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
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
T maxSpanningTree(const Undirgraph<T> &g) {
    vector<int> oedges(g.edges.size());
    iota(oedges.begin(), oedges.end(), 0);
    sort(oedges.begin(), oedges.end(), [&g](int a, int b) {
        return g.edges[a].cost > g.edges[b].cost;
    });

    T ans = 0;
    DSU dsu(g.n);
    for (int id : oedges) {
        auto &e = g.edges[id];
        if (dsu.find(e.from) != dsu.find(e.to)) {
            dsu.join(e.from, e.to);
            ans += e.cost;
        }
    }
    return ans;
}


LL solve() {
    int m, n; cin >> m >> n;
    VI a(m), b(n);
    REP(i, m) cin >> a[i];
    REP(i, n) cin >> b[i];

    Undirgraph<LL> g(m + n);

    LL ans = 0;

    REP(i, m) {
        int k = 0; cin >> k;
        while (k--) {
            int j; cin >> j;
            j--;
            g.addEdge(i, m + j, a[i] + b[j]);   
            ans += a[i] + b[j];
        }
    }

    return ans - maxSpanningTree(g);
}

int main() {
    setIO();
    int t=1; // cin>>t;
    while(t--) { 
        cout<<solve()<<"\n";
    }
    
    return 0;
}