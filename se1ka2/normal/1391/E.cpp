#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Graph
{
    int n;
    vector<vector<int>> g;
    
    Graph(int n) : n(n){
        g.resize(n);
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

void dfs(int u, Graph &g, int *p){
    for(int v : g.g[u]){
        if(p[v] == -1){
            p[v] = u;
            dfs(v, g, p);
        }
    }
}

int p[500005];
int ans[5000005][2];

int main()
{
    int q;
    cin >> q;
    while(q--){
        int n, m;
        cin >> n >> m;
        Graph g(n);
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g.add_edge(u, v);
            g.add_edge(v, u);
        }
        for(int u = 1; u < n; u++) p[u] = -1;
        dfs(0, g, p);
        Graph g2(n);
        for(int u = 1; u < n; u++){
            g2.add_edge(u, p[u]);
            g2.add_edge(p[u], u);
        }
        Tree t(g2, 0);
        vector<int> d = t.toposort();
        if(t.dpt[d[n - 1]] >= (n - 1) / 2){
            printf("PATH\n");
            int u = d[n - 1];
            printf("%d\n", t.dpt[u] + 1);
            while(u != -1){
                printf("%d ", u + 1);
                u = t.par[u];
            }
            printf("\n");
        }
        else{
            printf("PAIRING\n");
            int c = 0;
            for(int i = 1; i < n - 1; i++){
                int u = d[i], v = d[i + 1];
                int j = i + 1;
                while(t.par[v] == u && ++j < n) v = d[j];
                if(j == n || t.dpt[u] < t.dpt[v] - 1) continue;
                swap(d[i + 1], d[j]);
                ans[c][0] = u, ans[c][1] = v;
                c++;
                i++;
            }
            printf("%d\n", c);
            for(int i = 0; i < c; i++) printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
        }
    }
}