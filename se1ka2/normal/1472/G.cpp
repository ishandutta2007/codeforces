#include <iostream>
#include <queue>
using namespace std;

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

vector<int> e[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        Graph g(n), r(n);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            g.add_edge(u, v);
            r.add_edge(v, u);
        }
        vector<int> d = bfs(g, 0);
        for(int i = 0; i < n; i++) e[d[i]].push_back(i);
        int ans[200005];
        for(int i = 0; i < n; i++) ans[i] = n;
        for(int i = 0; i < n; i++){
            queue<int> que;
            for(int u : e[i]){
                if(ans[u] == n) ans[u] = i;
                for(int v : r.g[u]){
                    if(d[v] > d[u] && ans[v] == n){
                        ans[v] = i;
                        que.push(v);
                    }
                }
            }
            while(que.size()){
                int u = que.front();
                que.pop();
                for(int v : r.g[u]){
                    if(d[v] < d[u] && ans[v] == n){
                        ans[v] = i;
                        que.push(v);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
        for(int i = 0; i < n; i++) e[i].clear();
    }
}