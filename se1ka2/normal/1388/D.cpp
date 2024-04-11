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

int main()
{
    int n;
    cin >> n;
    ll a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    Graph g(n + 1);
    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        b--;
        if(b == -2) b = n;
        g.add_edge(b, i);
        g.add_edge(i, b);
    }
    Tree t(g, n);
    vector<int> d = t.toposort();
    Graph p(n);
    for(int i = 0; i < n; i++){
        int u = d[i];
        for(int v : t.t[u]){
            if(a[v] > 0){
                a[u] += a[v];
                p.add_edge(v, u);
            }
            else{
                p.add_edge(u, v);
            }
        }
    }
    ll ans = 0;
    for(int u = 0; u < n; u++) ans += a[u];
    cout << ans << endl;
    int c[200005]{0};
    for(int u = 0; u < n; u++){
        for(int v : p.g[u]) c[v]++;
    }
    queue<int> que;
    for(int u = 0; u < n; u++){
        if(c[u] == 0) que.push(u);
    }
    int l[200005];
    int i = 0;
    while(que.size()){
        int u = que.front();
        que.pop();
        l[i] = u;
        i++;
        for(int v : p.g[u]){
            c[v]--;
            if(c[v] == 0) que.push(v);
        }
    }
    for(i = 0; i < n; i++) cout << l[i] + 1 << " ";
}