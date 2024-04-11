#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const ll INF = 10000000000000;

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
    
    void add_edge(int from, int to, T cost){
        g[from].push_back((Edge<T>){to, cost});
    }
};

template <typename T>
vector<T> Dijkstra(WeightedGraph<T> &g, int s){
    typedef pair<T, int> P;
    int n = g.n;
    vector<T> d(n);
    fill(d.begin(), d.end(), INF);
    priority_queue<P, vector<P>, greater<P>> que;
    d[s] = 0;
    que.push(P(0, s));
    while(que.size()){
        P nowp = que.top();
        que.pop();
        if(d[nowp.second] < nowp.first) continue;
        for(Edge<T> e : g.g[nowp.second]){
            if(d[e.to] > d[nowp.second] + e.cost){
                d[e.to] = d[nowp.second] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    WeightedGraph<ll> g(n);
    int x[1002], y[1002];
    for(int i = 0; i < m; i++){
        ll w;
        cin >> x[i] >> y[i] >> w;
        x[i]--; y[i]--;
        g.add_edge(x[i], y[i], w);
        g.add_edge(y[i], x[i], w);
    }
    vector<ll> d[1002];
    for(int i = 0; i < n; i++){
        d[i] = Dijkstra(g, i);
    }
    int a[1002], b[1002];
    for(int i = 0; i < k; i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    ll ans = INF;
    for(int i = 0; i < m; i++){
        ll s = 0;
        for(int j = 0; j < k; j++){
            s += min(d[a[j]][b[j]], min(d[a[j]][x[i]] + d[b[j]][y[i]], d[a[j]][y[i]] + d[b[j]][x[i]]));
        }
        ans = min(ans, s);
    }
    cout << ans << endl;
}