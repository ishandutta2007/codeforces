#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

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

std::vector<int> bipartite_graph(Graph &g){
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
            for(int v : g.g[u]){
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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        Graph g(n);
        ll l[200005], r[200005];
        for(int i = 0; i < n; i++) cin >> l[i];
        for(int i = 0; i < n; i++) cin >> r[i];
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            a--; b--;
            g.add_edge(a, b);
            g.add_edge(b, a);
        }
        vector<int> b = bipartite_graph(g);
        if(b[n] == 0){
            ll x = 0;
            for(int i = 0; i < n; i++) x += l[i];
            for(int i = 0; i < n; i++) x += r[i];
            if(x % 2) cout << "NO" << endl;
            else cout << "YES" << endl;
            continue;
        }
        ll s[2]{0};
        for(int i = 0; i < n; i++) s[b[i]] += r[i] - l[i];
        if(s[0] == s[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}