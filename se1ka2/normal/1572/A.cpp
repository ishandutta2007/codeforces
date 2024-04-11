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

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Graph g(n), r(n);
        for(int u = 0; u < n; u++){
            int k;
            cin >> k;
            for(int i = 0; i < k; i++){
                int v;
                cin >> v;
                v--;
                g.add_edge(u, v);
                r.add_edge(v, u);
            }
        }
        queue<int> que;
        int d[200005];
        for(int u = 0; u < n; u++){
            d[u] = g.g[u].size();
            if(d[u] == 0) que.push(u);
        }
        int s[200005];
        while(que.size()){
            int u = que.front();
            que.pop();
            s[u] = 0;
            for(int v : g.g[u]){
                if(v < u) s[u] = max(s[u], s[v]);
                else s[u] = max(s[u], s[v] + 1);
            }
            for(int v : r.g[u]){
                d[v]--;
                if(d[v] == 0) que.push(v);
            }
        }
        bool f = true;
        for(int u = 0; u < n; u++){
            if(d[u]) f = false;
        }
        if(!f){
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        for(int u = 0; u < n; u++) ans = max(ans, s[u]);
        cout << ans + 1 << endl;
    }
}