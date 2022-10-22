#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const ll INF = 100000000000000000;

struct Graph
{
    int n;
    std::vector<std::vector<int>> g;
    
    Graph(){}
    
    Graph(int n) : n(n){
        g.resize(n);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

std::vector<int> bfs(Graph &g, int s){
    int n = g.n;
    std::vector<int> d(n);
    fill(d.begin(), d.end(), -1);
    std::queue<int> que;
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

ll a[2005][2005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll w;
    cin >> n >> m >> w;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    Graph g(n * m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i < n - 1 && a[i][j] != -1 && a[i + 1][j] != -1){
                g.add_edge(i * m + j, (i + 1) * m + j);
                g.add_edge((i + 1) * m + j, i * m + j);
            }
            if(j < m - 1 && a[i][j] != -1 && a[i][j + 1] != -1){
                g.add_edge(i * m + j, i * m + (j + 1));
                g.add_edge(i * m + (j + 1), i * m + j);
            }
        }
    }
    vector<int> d = bfs(g, 0);
    vector<int> e = bfs(g, n * m - 1);
    ll ans = INF;
    if(d[n * m - 1] != -1) ans = d[n * m - 1] * w;
    ll s = INF, t = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(d[i * m + j] != -1 && a[i][j] >= 1) s = min(s, d[i * m + j] * w + a[i][j]);
            if(e[i * m + j] != -1 && a[i][j] >= 1) t = min(t, e[i * m + j] * w + a[i][j]);
        }
    }
    ans = min(ans, s + t);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}