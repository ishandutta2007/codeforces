#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

const ll INF = 10000000000000000;

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

vector<P> Dijkstra(WeightedGraph<P> &g, int s){
    int n = g.n;
    vector<P> d(n);
    fill(d.begin(), d.end(), P(INF, -1));
    priority_queue<P, vector<P>, greater<P>> que;
    d[s].first = 0;
    que.push(P(0, s));
    while(que.size()){
        P nowp = que.top();
        que.pop();
        if(d[nowp.second].first < nowp.first) continue;
        for(Edge<P> e : g.g[nowp.second]){
            if(d[e.to].first > d[nowp.second].first + e.cost.first){
                d[e.to].first = d[nowp.second].first + e.cost.first;
                d[e.to].second = e.cost.second;
                que.push(P(d[e.to].first, e.to));
            }
        }
    }
    return d;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    WeightedGraph<P> g(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        ll w;
        cin >> w;
        g.add_edge(x, y, P(w, i));
        g.add_edge(y, x, P(w, i));
    }
    vector<P> v = Dijkstra(g, 0);
    sort(v.begin(), v.end());
    cout << min(k, n - 1) << endl;
    for(int i = 1; i < min(k + 1, n); i++){
        cout << v[i].second + 1 << " ";
    }
    cout << endl;
}