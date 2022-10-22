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

P d[200005];

P dfs(Tree &t, int u){
    if(d[u].first) return d[u];
    P res = P(0, u);
    for(int v : t.t[u]){
        P p = dfs(t, v);
        res = max(res, P(p.first + 1, p.second));
    }
    return d[u] = res;
}

int main()
{
    int n;
    cin >> n;
    Graph g(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    Tree tt(g, 0);
    int l = 0;
    for(int i = 0; i < n; i++){
        if(tt.dpt[i] > tt.dpt[l]) l = i;
    }
    Tree t(g, l);
    int r = 0;
    for(int i = 0; i < n; i++){
        if(t.dpt[i] > t.dpt[r]) r = i;
    }
    int dis = t.dpt[r];
    P lp = P(-1, -1);
    for(int u = r; u != l; u = t.par[u]){
        for(int v : t.t[t.par[u]]){
            if(u == v) continue;
            lp = max(lp, dfs(t, v));
        }
    }
    if(lp.first == -1){
        for(int u = 0; u < n; u++) if(u != l && u != r){
            cout << dis << endl;
            cout << l + 1 << " " << r + 1 << " " << u + 1 << endl;
            return 0;
        }
    }
    cout << dis + lp.first + 1 << endl;
    cout << l + 1 << " " << r + 1 << " " << lp.second + 1 << endl;
}