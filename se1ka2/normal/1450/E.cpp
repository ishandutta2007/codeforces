#include <iostream>
#include <queue>
using namespace std;

const int INF = 10000000;

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

std::vector<int> bipartite_graph(WeightedGraph<int> &g){
    int n = g.n;
    std::vector<int> b(n + 1, -1);
    b[n] = 0;
    std::queue<int> que;
    for(int i = 0; i < n; i++){
        if(b[i] != -1) continue;
        b[i] = 0;
        que.push(i);
        while(que.size()){
            int u = que.front();
            que.pop();
            for(Edge<int> e : g.g[u]){
                int v = e.to;
                if(b[u] == b[v]) return b;
                if(b[v] == -1){
                    b[v] = 1 - b[u];
                    que.push(v);
                }
            }
        }
    }
    b[n] = 1;
    return b;
}

int main()
{
    int n, m;
    cin >> n >> m;
    WeightedGraph<int> g(n);
    for(int i = 0; i < m; i++){
        int u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        g.add_edge(u, v, b);
        g.add_edge(v, u, -b);
    }
    vector<int> b = bipartite_graph(g);
    if(b[n] == 0){
        cout << "NO" << endl;
        return 0;
    }
    queue<int> que;
    int low[100005], high[100005];
    int ans = 0;
    int a[100005];
    for(int r = 0; r < n; r++){
        for(int i = 0; i < n; i++){
            low[i] = -INF, high[i] = INF;
        }
        low[r] = 0, high[r] = 0;
        queue<int> que;
        que.push(r);
        while(que.size()){
            int u = que.front();
            que.pop();
            if(low[u] > high[u]){
                cout << "NO" << endl;
                return 0;
            }
            for(Edge<int> e : g.g[u]){
                int v = e.to;
                if(e.cost != 0){
                    if(low[v] < low[u] + e.cost || high[v] > high[u] + e.cost){
                        low[v] = max(low[v], low[u] + e.cost);
                        high[v] = min(high[v], high[u] + e.cost);
                        que.push(v);
                    }
                }
                else{
                    if(low[v] < low[u] - 1 || high[v] > high[u] + 1){
                        low[v] = max(low[v], low[u] - 1);
                        high[v] = min(high[v], high[u] + 1);
                        que.push(v);
                    }
                }
            }
        }
        int l = 0;
        for(int i = 0; i < n; i++) l = max(l, high[i]);
        if(l > ans){
            ans = l;
            for(int i = 0; i < n; i++) a[i] = high[i];
        }
    }
    cout << "YES" << endl;
    cout << ans << endl;
    for(int i = 0; i < n; i++) cout << a[i] + n << " ";
    cout << endl;
}