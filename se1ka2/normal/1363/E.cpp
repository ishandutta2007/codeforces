#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

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
    
    vector<int> toposort(){
        typedef pair<int, int> P;
        vector<P> p(n);
        for(int i = 0; i < n; i++) p[i] = P(dpt[i], i);
        sort(p.begin(), p.end());
        vector<int> res(n);
        for(int i = 0; i < n; i++) res[i] = p[i].second;
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    ll a[200005];
    int b[200005], c[200005];
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    Graph g(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.add_edge(u, v);
        g.add_edge(v, u);
    }
    Tree t(g, 0);
    vector<int> d = t.toposort();
    for(int i = 1; i < n; i++){
        int u = d[i];
        a[u] = min(a[u], a[t.par[u]]);
    }
    ll ans = 0;
    int o[200005]{0}, e[200005]{0};
    for(int i = n - 1; i >= 0; i--){
        int u = d[i];
        for(int v : t.t[u]){
            o[u] += o[v];
            e[u] += e[v];
        }
        if(b[u] > c[u]) o[u]++;
        if(b[u] < c[u]) e[u]++;
        if(o[u] > 0 && e[u] > 0){
            int l = min(o[u], e[u]);
            ans += l * a[u] * 2;
            o[u] -= l;
            e[u] -= l;
        }
    }
    if(o[0] != 0 || e[0] != 0) cout << -1 << endl;
    else cout << ans << endl;
}