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
    scanf("%d", &n);
    Graph g(n);
    for(int i = 1; i < n; i++){
        int p;
        scanf("%d", &p);
        p--;
        g.add_edge(i, p);
        g.add_edge(p, i);
    }
    Tree t(g, 0);
    ll a[200005];
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    int c[200005]{0};
    vector<int> p = t.toposort();
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int u = p[i];
        for(int v : t.t[u]){
            a[u] += a[v];
            c[u] += c[v];
        }
        if((int)t.t[u].size() == 0) c[u]++;
        ans = max(ans, (a[u] + c[u] - 1) / c[u]);
    }
    printf("%lld\n", ans);
}