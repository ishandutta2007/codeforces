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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
    queue<int> que1;
    int d[200005];
    for(int i = 0; i < n; i++){
        d[i] = (int)r.g[i].size();
        if(d[i] == 0) que1.push(i);
    }
    int k = 0;
    while(que1.size()){
        int u = que1.front();
        que1.pop();
        k++;
        for(int v : g.g[u]){
            d[v]--;
            if(d[v] == 0) que1.push(v);
        }
    }
    if(k < n){
        cout << -1 << "\n";
        return 0;
    }
    bool bg[200005]{0}, br[200005]{0};
    bool ans[200005]{0};
    for(int i = 0; i < n; i++){
        if(!bg[i] && !br[i]) ans[i] = true;
        queue<int> que;
        if(!bg[i]){
            bg[i] = true;
            que.push(i);
            while(que.size()){
                int u = que.front();
                que.pop();
                for(int v : g.g[u]){
                    if(!bg[v]){
                        bg[v] = true;
                        que.push(v);
                    }
                }
            }
        }
        if(!br[i]){
            br[i] = true;
            que.push(i);
            while(que.size()){
                int u = que.front();
                que.pop();
                for(int v : r.g[u]){
                    if(!br[v]){
                        br[v] = true;
                        que.push(v);
                    }
                }
            }
        }
    }
    k = 0;
    for(int i = 0; i < n; i++) k += ans[i];
    cout << k << endl;
    for(int i = 0; i < n; i++){
        if(ans[i]) cout << "A";
        else cout << "E";
    }
    cout << "\n";
}