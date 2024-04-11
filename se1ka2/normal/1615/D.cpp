#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct Edge
{
    int to;
    T cost;
};

template <typename T>
struct WeightedTree
{
    int n;
    int r;
    int l;
    std::vector<std::vector<Edge<T>>> prit;
    std::vector<std::vector<Edge<T>>> t;
    std::vector<Edge<T>> par;
    std::vector<int> dpt;
    std::vector<Edge<T>> tour;
    std::vector<std::vector<int>> appear_on_tour;
    std::vector<std::vector<int>> anc;
    
    WeightedTree(){}
    
    WeightedTree(int n) : n(n){
        prit.resize(n);
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
    }
    
    void add_edge(int u, int v, T cost){
        prit[u].push_back(Edge<T>{v, cost});
        prit[v].push_back(Edge<T>{u, cost});
    }
    
    void build(int r_){
        r = r_;
        for(int i = 0; i < n; i++) dpt[i] = -1;
        std::queue<int> que;
        par[r].to = -1;
        dpt[r] = 0;
        que.push(r);
        while(que.size()){
            int u = que.front();
            que.pop();
            for(Edge<T> &e : prit[u]){
                int v = e.to;
                if(dpt[v] == -1){
                    t[u].push_back(e);
                    par[v] = Edge<T>{u, e.cost};
                    dpt[v] = dpt[u] + 1;
                    que.push(v);
                }
            }
        }
    }
    
    void rebuild(int r_){
        for(int u = 0; u < n; u++) t[u].clear();
        build(r_);
    }
    
/*
    std::vector<int> toposort(){
        std::vector<std::pair<int, int>> p(n);
        for(int i = 0; i < n; i++) p[i] = std::pair<int, int>(dpt[i], i);
        sort(p.begin(), p.end(), std::greater<std::pair<int, int>>());
        std::vector<int> res(n);
        for(int i = 0; i < n; i++) res[i] = p[i].second;
        return res;
    }
*/
    
    void dfs(int u, int &k){
        for(Edge<T> &e : t[u]){
            appear_on_tour[u].push_back(k);
            tour[k++] = e;
            dfs(e.to, k);
        }
        appear_on_tour[u].push_back(k);
        tour[k++] = par[u];
    }
    
    void build_euler_tour(){
        tour.resize(n * 2 - 1);
        appear_on_tour.resize(n);
        int k = 0;
        dfs(0, k);
    }
    
    void build_lca(){
        for(l = 1; l <= n; l++){
            if((1 << (l - 1)) >= n) break;
        }
        anc.resize(l);
        for(int j = 0; j < l; j++) anc[j].resize(n);
        for(int i = 0; i < n; i++) anc[0][i] = par[i].to;
        for(int j = 1; j < l; j++){
            for(int i = 0; i < n; i++){
                if(anc[j - 1][i] == -1) anc[j][i] = -1;
                else anc[j][i] = anc[j - 1][anc[j - 1][i]];
            }
        }
    }
    
    int lca(int u, int v){
        if(dpt[u] < dpt[v]) std::swap(u, v);
        int dpt_diff = dpt[u] - dpt[v];
        for(int j = l - 1; j >= 0; j--){
            if((dpt_diff >> j) & 1) u = anc[j][u];
        }
        if(u == v) return u;
        for(int j = l - 1; j >= 0; j--){
            if(anc[j][u] != anc[j][v]){
                u = anc[j][u];
                v = anc[j][v];
            }
        }
        return anc[0][u];
    }
};

struct SCC      //StronglyConnectedComponents
{
    int n;
    int k;
    std::vector<std::vector<int>> g, rg;
    std::vector<bool> used;
    std::vector<int> cmp;
    std::vector<int> vs;
    
    SCC(){}
    
    SCC(int n) : n(n){
        g.resize(n);
        rg.resize(n);
        used.resize(n);
        cmp.resize(n);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
        rg[to].push_back(from);
    }
    
    void dfs(int u){
        used[u] = true;
        for(int v : g[u]){
            if(!used[v]) dfs(v);
        }
        vs.push_back(u);
    }
    
    void rdfs(int u, int k){
        used[u] = true;
        cmp[u] = k;
        for(int v : rg[u]){
            if(!used[v]) rdfs(v, k);
        }
    }
    
    int decomposition(){
        for(int i = 0; i < n; i++) used[i] = false;
        for(int i = 0; i < n; i++){
            if(!used[i]) dfs(i);
        }
        for(int i = 0; i < n; i++) used[i] = false;
        k = 0;
        for(int i = n - 1; i >= 0; i--){
            if(!used[vs[i]]){
                rdfs(vs[i], k);
                k++;
            }
        }
        return k;
    }
};

struct TwoSAT
{
    int n;
    SCC g;
    std::vector<bool> f;
    
    TwoSAT(int n) : n(n){
        g.n = n * 2;
        g.g.resize(n * 2);
        g.rg.resize(n * 2);
        g.used.resize(n * 2);
        g.cmp.resize(n * 2);
        f.resize(n);
    }
    
    void add_edge(int a, bool fa, int b, bool fb){
        g.add_edge(a + int(!fa) * n, b + int(fb) * n);
        g.add_edge(b + int(!fb) * n, a + int(fa) * n);
    }
    
    bool judge(){
        g.decomposition();
        for(int i = 0; i < n; i++){
            if(g.cmp[i] == g.cmp[i + n]) return false;
            if(g.cmp[i] > g.cmp[i + n]) f[i] = false;
            else f[i] = true;
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        TwoSAT g(n);
        WeightedTree<int> t(n);
        for(int i = 0; i < n - 1; i++){
            int a, b, v;
            cin >> a >> b >> v;
            a--; b--;
            t.add_edge(a, b, v);
            if(v != -1){
                int c = 0;
                for(int j = 0; j < 30; j++) c += (v >> j) & 1;
                if(c % 2 == 0){
                    g.add_edge(a, true, b, false);
                    g.add_edge(a, false, b, true);
                }
                else{
                    g.add_edge(a, true, b, true);
                    g.add_edge(a, false, b, false);
                }
            }
        }
        t.build(0);
        for(int i = 0; i < m; i++){
            int a, b, p;
            cin >> a >> b >> p;
            a--; b--;
            if(!p){
                g.add_edge(a, true, b, false);
                g.add_edge(a, false, b, true);
            }
            else{
                g.add_edge(a, true, b, true);
                g.add_edge(a, false, b, false);
            }
        }
        bool f = g.judge();
        if(!f){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int u = 0; u < n; u++){
            for(Edge<int> e : t.t[u]){
                int v = e.to;
                if(e.cost != -1) cout << u + 1 << " " << v + 1 << " " << e.cost << "\n";
                else cout << u + 1 << " " << v + 1 << " " << (g.f[u] ^ g.f[v]) << "\n";
            }
        }
    }
}