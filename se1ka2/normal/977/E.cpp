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

int main()
{
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
    bool looked[200005]{0};
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(looked[i]) continue;
        queue<int> que;
        looked[i] = true;
        que.push(i);
        bool f = true;
        while(que.size()){
            int u = que.front();
            que.pop();
            if((int)g.g[u].size() != 2) f = false;
            for(int v : g.g[u]){
                if(looked[v]) continue;
                looked[v] = true;
                que.push(v);
            }
        }
        ans += f;
    }
    cout << ans << endl;
}