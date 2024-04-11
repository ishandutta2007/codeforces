#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

struct Graph
{
    int n;
    vector<vector<int>> g;
    
    Graph(int n) : n(n){
        g.resize(n);
    }
    
    void init(int n_){
        n = n_;
        g.resize(n_);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

struct Tree	//create tree(directed) from graph(undirected)
{
    int n;
    int root;
    vector<vector<int>> t;
    vector<int> par;
    vector<int> dpt;
    
    void init(Graph &g, int root_){
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
            for(int ch : g.g[pa]){
                if(dpt[ch] == -1){
                    t[pa].push_back(ch);
                    par[ch] = pa;
                    dpt[ch] = dpt[pa] + 1;
                    que.push(ch);
                }
            }
        }
    }

    Tree(){}
    
    Tree(Graph &g, int root_){
        init(g, root_);
    }
};

struct LCA
{
    int k;
    int n;
    vector<int> dpt;
    vector<vector<int>> par;    // par[j][i] : the (2^j)th parent of i;
    
    LCA(Tree &t){
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

template <typename S>   //semi group
struct UnionFind
{
    using F = function<S(S, S)>;
    
    const F f;
    
    vector<int> par, rank;
    vector<S> dat;
    
    UnionFind(int n, const F f = [](S a, S b){return a + b;}) : f(f){
        par.resize(n);
        rank.resize(n);
        dat.assign(n, 1);
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
        if(rank[i] < rank[j]){
            par[i] = j;
            dat[j] = f(dat[i], dat[j]);
        }
        else{
            par[j] = i;
            dat[i] = f(dat[i], dat[j]);
            if(rank[i] == rank[j]) rank[i]++;
        }
    }
    
    S query(int i){
        return dat[find(i)];
    }
};

int f(Tree &t, int a, int b){
    if(t.dpt[a] < t.dpt[b]) return a;
    else return b;
}

int x[300005], y[300005];
P p[300005];
int d[300005];

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g1(n);
    UnionFind<int> uf1(n);
    vector<int> vec;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &x[i], &y[i]);
        x[i]--; y[i]--;
        if(uf1.same(x[i], y[i])) vec.push_back(i);
        else{
            g1.add_edge(x[i], y[i]);
            g1.add_edge(y[i], x[i]);
            uf1.unite(x[i], y[i]);
        }
    }
    Tree t(g1, 0);
    LCA lca(t);
    UnionFind<int> uf2(n, [&](int a, int b){return f(t, a, b);});
    for(int i = 0; i < n; i++) uf2.dat[i] = i;
    for(int i : vec){
        int u = x[i], v = y[i];
        int w = lca.query(u, v);
        uf2.unite(u, w);
        uf2.unite(v, w);
    }
    for(int i = 0; i < n; i++) p[i] = P(t.dpt[i], i);
    sort(p, p + n, greater<P>());
    for(int i = 0; i < n; i++){
        int u = p[i].second;
        for(int v : t.t[u]){
            if(t.dpt[u] >= t.dpt[uf2.query(v)]) uf2.unite(u, v);
        }
    }
    Graph g2(n);
    UnionFind<int> uf3(n);
    for(int i = 0; i < m; i++){
        int u = uf2.find(x[i]), v = uf2.find(y[i]);
        if(!uf3.same(u, v)){
            g2.add_edge(u, v);
            g2.add_edge(v, u);
            uf3.unite(u, v);
        }
    }
    int r = uf2.find(0);
    fill(d, d + n, -1);
    queue<int> que;
    d[r] = 0;
    que.push(r);
    int u = -1;
    while(que.size()){
        u = que.front();
        que.pop();
        for(int v : g2.g[u]){
            if(d[v] != -1) continue;
            d[v] = d[u] + 1;
            que.push(v);
        }
    }
    r = u;
    fill(d, d + n, -1);
    d[r] = 0;
    que.push(r);
    while(que.size()){
        u = que.front();
        que.pop();
        for(int v : g2.g[u]){
            if(d[v] != -1) continue;
            d[v] = d[u] + 1;
            que.push(v);
        }
    }
    cout << d[u] << endl;
}