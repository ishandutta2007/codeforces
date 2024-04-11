#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

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
    std::vector<std::vector<Edge<T>>> g;
    
    WeightedGraph(){}
    
    WeightedGraph(int n) : n(n){
        g.resize(n);
    }
    
    void add_edge(int from, int to, T cost){
        g[from].push_back((Edge<T>){to, cost});
    }
};

template <typename T>
std::vector<T> dijkstra(WeightedGraph<T> &g, int s){
    int n = g.n;
    std::vector<T> d(n);
    fill(d.begin(), d.end(), -1);
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;
    d[s] = 0;
    que.push(std::pair<T, int>(0, s));
    while(que.size()){
        std::pair<T, int> p = que.top();
        que.pop();
        int u = p.second;
        if(d[u] < p.first) continue;
        for(Edge<T> &e : g.g[u]){
            int v = e.to;
            if(d[v] == -1 || d[v] > d[u] + e.cost){
                d[v] = d[u] + e.cost;
                que.push(std::pair<T, int>(d[v], v));
            }
        }
    }
    return d;
}

int main()
{
    int n, m;
    cin >> n >> m;
    WeightedGraph<ll> g(n * 4);
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        for(int j = 0; j < 4; j++){
            g.add_edge(u * 4 + j, v * 4 + j, w);
            g.add_edge(v * 4 + j, u * 4 + j, w);
        }
        for(int j = 0; j < 2; j++){
            g.add_edge(u * 4 + j, v * 4 + j + 2, 0);
            g.add_edge(v * 4 + j, u * 4 + j + 2, 0);
        }
        for(int j = 0; j < 2; j++){
            g.add_edge(u * 4 + j * 2, v * 4 + j * 2 + 1, w * 2);
            g.add_edge(v * 4 + j * 2, u * 4 + j * 2 + 1, w * 2);
        }
        g.add_edge(u * 4, v * 4 + 3, w);
        g.add_edge(v * 4, u * 4 + 3, w);
    }
    vector<ll> d = dijkstra(g, 0);
    for(int i = 1; i < n; i++) cout << d[i * 4 + 3] << " ";
    cout << endl;
}