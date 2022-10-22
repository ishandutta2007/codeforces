#include <iostream>
#include <queue>
using namespace std;

struct UnionFind
{
    std::vector<int> par, sz;
    
    UnionFind(int n){
        par.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            sz[i] = 1;
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
        i = find(i), j = find(j);
        if(i == j) return;
        if(sz[i] < sz[j]) std::swap(i, j);
        par[j] = i;
        sz[i] += sz[j];
    }
    
    int size(int i){
        return sz[find(i)];
    }
};

struct Graph
{
    int n;
    std::vector<std::vector<int>> g;
    
    Graph(){}
    
    Graph(int n) : n(n){
        g.resize(n);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

bool used[300005];

void dfs(int u, Graph &g, vector<int> &ans){
    queue<int> que;
    for(int v : g.g[u]){
        if(used[v]) continue;
        used[v] = true;
        que.push(v);
    }
    while(que.size()){
        int v = que.front();
        que.pop();
        for(int w : g.g[v]){
            if(!used[w]){
                used[w] = true;
                ans.push_back(w);
                dfs(w, g, ans);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        UnionFind uf(n);
        Graph g(n);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
            g.add_edge(u, v);
            g.add_edge(v, u);
        }
        if(uf.size(0) != n){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        vector<int> ans;
        for(int i = 0; i < n; i++) used[i] = false;
        used[0] = true;
        ans.push_back(0);
        dfs(0, g, ans);
        cout << (int)ans.size() << endl;
        for(int u : ans) cout << u + 1 << " ";
        cout << endl;
    }
}