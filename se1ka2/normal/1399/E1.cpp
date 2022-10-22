#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;

template <typename T>
struct Edge
{
    int to;
    T cost;
};

template <typename T>
struct WeightedGraph
{
    int n;
    vector<vector<Edge<T>>> g;
    
    WeightedGraph(int n) : n(n){
        g.resize(n);
    }
    
    void init(int n_){
        n = n_;
        g.resize(n_);
    }
    
    void add_edge(int from, int to, T cost){
        g[from].push_back((Edge<T>){to, cost});
    }
};

template <typename T>
struct WeightedTree
{
    int n;
    int root;
    vector<vector<Edge<T>>> t;
    vector<int> par;
    vector<int> dpt;

    void init(WeightedGraph<T> &g, int root_){
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
            for(Edge<T> e : g.g[pa]){
                int ch = e.to;
                if(dpt[ch] == -1){
                    t[pa].push_back(e);
                    par[ch] = pa;
                    dpt[ch] = dpt[pa] + 1;
                    que.push(ch);
                }
            }
        }
    }
    
    WeightedTree(){}
    
    WeightedTree(WeightedGraph<T> &g, int root_){
        init(g, root_);
    }
};

ll dfs(int u, priority_queue<PP> &que, WeightedTree<ll> &t, ll &s){
    ll res;
    if(t.t[u].size()) res = 0;
    else res = 1;
    for(Edge<ll> e : t.t[u]){
        int v = e.to;
        ll k = dfs(v, que, t, s);
        res += k;
        que.push(PP((e.cost + 1) / 2 * k, P(k, e.cost / 2)));
        s -= e.cost * k;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        ll s;
        cin >> n >> s;
        WeightedGraph<ll> g(n);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            ll w;
            cin >> u >> v >> w;
            u--; v--;
            g.add_edge(u, v, w);
            g.add_edge(v, u, w);
        }
        WeightedTree t(g, 0);
        priority_queue<PP> que;
        dfs(0, que, t, s);
        int ans = 0;
        while(s < 0){
            PP p = que.top();
            que.pop();
            s += p.first;
            que.push(PP((p.second.second + 1) / 2 * p.second.first, P(p.second.first, p.second.second / 2)));
            ans++;
        }
        cout << ans << endl;
    }
}