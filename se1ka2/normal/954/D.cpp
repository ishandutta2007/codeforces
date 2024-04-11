#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

vector<int> dijkstra(Graph &g, int s)
{
    int n = g.n;
    vector<int> d(n);
    fill(d.begin(), d.end(), -1);
    queue<int> que;
    d[s] = 0;
    que.push(s);
    while(que.size()){
        int u = que.front();
        que.pop();
        for(int v : g.g[u]){
            if(d[v] == -1){
                d[v] = d[u] + 1;
                que.push(v);
            }
        }
    }
    return d;
}

bool b[1002][1002];

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    Graph g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.add_edge(u, v);
        g.add_edge(v, u);
        b[u][v] = true;
        b[v][u] = true;
    }
    vector<int> ds = dijkstra(g, s);
    vector<int> dt = dijkstra(g, t);
    int ans = 0;
    for(int u = 0; u < n; u++){
        for(int v = u + 1; v < n; v++){
            if(b[u][v]) continue;
            if(min(ds[u] + dt[v], ds[v] + dt[u]) + 1 >= ds[t]) ans++;
        }
    }
    cout << ans << endl;
}