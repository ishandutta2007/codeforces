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
        sort(p.begin(), p.end(), greater<P>());
        vector<int> res(n);
        for(int i = 0; i < n; i++) res[i] = p[i].second;
        return res;
    }
};

int dfs(int u, Tree &t, int *d){
    int l = 0, s = 1;
    for(int v : t.t[u]){
        int x = dfs(v, t, d);
        l = max(l, x);
        s += x;
    }
    d[u] = max(l, t.n - s);
    return s;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Graph g(n);
        int x[300005], y[300005];
        for(int i = 0; i < n - 1; i++){
            scanf("%d %d", &x[i], &y[i]);
            x[i]--; y[i]--;
            g.add_edge(x[i], y[i]);
            g.add_edge(y[i], x[i]);
        }
        Tree t(g, 0);
        int d[300005];
        dfs(0, t, d);
        int s = n;
        int b[2] = {-1, -1};
        for(int i = 0; i < n; i++) s = min(s, d[i]);
        for(int i = 0; i < n; i++){
            if(d[i] == s){
                if(b[0] == -1) b[0] = i;
                else b[1] = i;
            }
        }
        if(b[1] == -1){
            cout << x[0] + 1 << " " << y[0] + 1 << endl;
            cout << x[0] + 1 << " " << y[0] + 1 << endl;
        }
        else{
            for(int i = 0; i < n; i++){
                if(x[i] == b[0] || y[i] == b[0]){
                    if(x[i] == b[1] || y[i] == b[1]) continue;
                    cout << x[i] + 1 << " " << y[i] + 1 << endl;
                    if(x[i] == b[0]) cout << y[i] + 1 << " " << b[1] + 1 << endl;
                    else cout << x[i] + 1 << " " << b[1] + 1 << endl;
                    break;
                }
            }
        }
    }
}