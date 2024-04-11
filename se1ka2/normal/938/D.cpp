#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1000000000000000000;

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

int main()
{
    int n, m;
    cin >> n >> m;
    WeightedGraph<ll> g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        g.add_edge(u, v, w * 2);
        g.add_edge(v, u, w * 2);
    }
    ll a[200005];
    ll ans[200005];
    fill(ans, ans + n, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans[i] = a[i];
        que.push(P(a[i], i));
    }
    while(que.size()){
        P p = que.top();
        que.pop();
        int u = p.second;
        ll c = p.first;
        if(ans[u] < c) continue;
        for(Edge<ll> e : g.g[u]){
            int v = e.to;
            if(ans[v] > ans[u] + e.cost){
                ans[v] = ans[u] + e.cost;
                que.push(P(ans[v], v));
            }
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}