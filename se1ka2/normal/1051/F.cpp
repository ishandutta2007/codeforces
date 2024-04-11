#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, P> PP;

const ll INF = 100000000000000000;

class UnionFind
{
    vector<int> par, rank;
    
public:
    UnionFind(int n){
        par.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }
    
    bool same(int i, int j){
        return find(i) == find(j);
    }
    
    void unite(int i, int j){
        if(same(i, j)) return;
        i = find(i), j = find(j);
        if(rank[i] < rank[j]) par[i] = j;
        else{
            par[j] = i;
            if(rank[i] == rank[j]) rank[i]++;
        }
    }
};

template <typename T>
struct Edge
{
    int to;
    T cost;
};

template <typename T>
struct WeightedGraph
{
    int n;
    vector<vector<Edge<T>>> g;
    
    WeightedGraph(int n) : n(n){
        g.resize(n);
    }
    
    void init(int n_){
        n = n_;
        g.resize(n_);
    }
    
    void add_edge(int from, int to, T cost){
        g[from].push_back((Edge<T>){to, cost});
    }
};

template <typename T>
struct WeightedTree
{
    int n;
    int root;
    vector<vector<Edge<T>>> t;
    vector<int> par;
    vector<int> dpt;

    void init(WeightedGraph<T> &g, int root_){
        n = g.n;
        root = root_;
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
        fill(dpt.begin(), dpt.end(), -1);
        queue<int> que;
        par[root] = -1;
        dpt[root] = 0;
        que.push(root);
        while(que.size()){
            int pa = que.front();
            que.pop();
            for(Edge<T> e : g.g[pa]){
                int ch = e.to;
                if(dpt[ch] == -1){
                    t[pa].push_back(e);
                    par[ch] = pa;
                    dpt[ch] = dpt[pa] + 1;
                    que.push(ch);
                }
            }
        }
    }
    
    WeightedTree(){}
    
    WeightedTree(WeightedGraph<T> &g, int root_){
        init(g, root_);
    }
};

template <typename T>
struct LCA
{
    int k;
    int n;
    vector<int> dpt;
    vector<vector<int>> par;    // par[j][i] : the (2^j)th parent of i;
    
    LCA(WeightedTree<T> &t){
        n = t.n;
        for(k = 1; k <= n; k++){
            if((1 << (k - 1)) >= n) break;
        }
        dpt = t.dpt;
        par.resize(k);
        for(int j = 0; j < k; j++) par[j].resize(n);
        for(int i = 0; i < n; i++) par[0][i] = t.par[i];
        for(int j = 1; j < k; j++){
            for(int i = 0; i < n; i++){
                if(par[j - 1][i] == -1) par[j][i] = -1;
                else par[j][i] = par[j - 1][par[j - 1][i]];
            }
        }
    }
    
    int query(int u, int v){
        if(dpt[u] < dpt[v]) swap(u, v);
        int r = dpt[u] - dpt[v];
        for(int j = k - 1; j >= 0; j--) if((r >> j) & 1) u = par[j][u];
        if(u == v) return u;
        for(int j = k - 1; j >= 0; j--) if(par[j][u] != par[j][v]) u = par[j][u], v = par[j][v];
        return par[0][u];
    }
};

template <typename T>
vector<T> Dijkstra(WeightedGraph<T> &g, int s){
    typedef pair<T, int> P;
    int n = g.n;
    vector<T> d(n);
    fill(d.begin(), d.end(), INF);
    priority_queue<P, vector<P>, greater<P>> que;
    d[s] = 0;
    que.push(P(0, s));
    while(que.size()){
        P nowp = que.top();
        que.pop();
        if(d[nowp.second] < nowp.first) continue;
        for(Edge<T> e : g.g[nowp.second]){
            if(d[e.to] > d[nowp.second] + e.cost){
                d[e.to] = d[nowp.second] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d;
}

int main()
{
    int n, m;
    cin >> n >> m;
    WeightedGraph<ll> g(n);
    priority_queue<PP, vector<PP>, greater<PP>> que;
    for(int i = 0; i < m; i++){
        int u, v;
        ll d;
        cin >> u >> v >> d;
        u--; v--;
        g.add_edge(u, v, d);
        g.add_edge(v, u, d);
        que.push(PP(d, P(u, v)));
    }
    UnionFind uf(n);
    WeightedGraph<ll> h(n);
    vector<int> r;
    r.push_back(0);
    while(que.size()){
        PP pp = que.top();
        que.pop();
        int u = pp.second.first, v = pp.second.second;
        if(uf.same(u, v)){
            r.push_back(u);
            r.push_back(v);
        }
        else{
            uf.unite(u, v);
            h.add_edge(u, v, pp.first);
            h.add_edge(v, u, pp.first);
        }
    }
    WeightedTree<ll> t(h, 0);
    LCA<ll> lca(t);
    vector<ll> d[50];
    d[0] = Dijkstra<ll>(h, 0);
    for(int i = 1; i < (int)r.size(); i++) d[i] = Dijkstra<ll>(g, r[i]);
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        int w = lca.query(u, v);
        ll ans = d[0][u] + d[0][v] - d[0][w] * 2;
        for(int i = 1; i < (int)r.size(); i++) ans = min(ans, d[i][u] + d[i][v]);
        cout << ans << endl;
    }
}