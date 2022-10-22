#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = 998244353;

ll modpow(ll x, ll n){
    ll res = 1, r = x;
    while(n){
        if(n % 2) res = res * r % MOD;
        r = r * r % MOD;
        n /= 2;
    }
    return res;
}

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

P BipartiteGraph(Graph &g, vector<int> &b, int i){
    ll e = 0, o = 0;
    int n = g.n;
    queue<int> que;
    b[i] = 1;
    o++;
    que.push(i);
    while(que.size()){
        int u = que.front();
        que.pop();
        for(int v : g.g[u]){
            if(b[u] == b[v]){
                for(int i = 0; i < n; i++) b[i] = -1;
                return P(-1, -1);
            }
            if(b[v] == 0){
                b[v] = 3 - b[u];
                if(b[v] == 2) e++;
                else o++;
                que.push(v);
            }
        }
    }
    return P(o, e);
}

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, m;
        cin >> n >> m;
        Graph g(n);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            g.add_edge(u, v);
            g.add_edge(v, u);
        }
        vector<int> b(n);
        ll ans = 1;
        for(int i = 0; i < n; i++){
            if(b[i]) continue;
            P p = BipartiteGraph(g, b, i);
            if(p.first == -1) ans = 0;
            ans = ans * ((modpow(2, p.first) + modpow(2, p.second)) % MOD) % MOD;
        }
        cout << ans << endl;
    }
}