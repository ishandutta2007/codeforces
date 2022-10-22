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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        ll p[100005], h[100005];
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cin >> h[i];
        Graph g(n);
        for(int i = 0; i < n - 1; i++){
            int x, y;
            cin >> x >> y;
            x--; y--;
            g.add_edge(x, y);
            g.add_edge(y, x);
        }
        Tree t(g, 0);
        vector<int> d = t.toposort();
        for(int i = 0; i < n; i++){
            int u = d[i];
            for(int v : t.t[u]) p[u] += p[v];
        }
        ll good[100005], bad[100005];
        bool f = true;
        for(int u = 0; u < n; u++){
            if((p[u] + h[u]) % 2) f = false;
            good[u] = (p[u] + h[u]) / 2;
            bad[u] = (p[u] - h[u]) / 2;
            if(good[u] < 0 || bad[u] < 0) f = false;
        }
        for(int u = 0; u < n; u++){
            ll s = 0;
            for(int v : t.t[u]) s += good[v];
            if(s > good[u]) f = false;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}