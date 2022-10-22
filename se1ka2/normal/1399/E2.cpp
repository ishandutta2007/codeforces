#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct str
{
    ll sub;
    int b;
    ll k;
    ll c;
    
    bool operator<(const str &s) const{
        return sub < s.sub;
    }
};

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

ll dfs(int u, priority_queue<str> &que, WeightedTree<P> &t, ll &s){
    ll res;
    if(t.t[u].size()) res = 0;
    else res = 1;
    for(Edge<P> e : t.t[u]){
        int v = e.to;
        ll k = dfs(v, que, t, s);
        res += k;
        que.push(str{(e.cost.first + 1) / 2 * k, e.cost.second, k, e.cost.first / 2});
        s -= e.cost.first * k;
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
        WeightedGraph<P> g(n);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            ll w;
            int c;
            cin >> u >> v >> w >> c;
            u--; v--;
            g.add_edge(u, v, P(w, c));
            g.add_edge(v, u, P(w, c));
        }
        WeightedTree<P> t(g, 0);
        priority_queue<str> que;
        priority_queue<ll, vector<ll>, greater<ll>> quee;
        dfs(0, que, t, s);
        int ans = 0;
        while(s < 0){
            str p = que.top();
            que.pop();
            s += p.sub;
            que.push(str{(p.c + 1) / 2 * p.k, p.b, p.k, p.c / 2});
            ans += p.b;
            if(p.b == 2){
                quee.push(p.sub);
            }
        }
        int k = ans;
        while(quee.size()){
            s -= quee.top();
            quee.pop();
            k -= 2;
            while(s < 0 && !que.empty()){
                str p = que.top();
                que.pop();
                if(p.sub == 0) break;
                if(p.b == 2) continue;
                s += p.sub;
                que.push(str{(p.c + 1) / 2 * p.k, p.b, p.k, p.c / 2});
                k++;
            }
            if(s < 0) break;
            ans = min(ans, k);
        }
        cout << ans << endl;
    }
}