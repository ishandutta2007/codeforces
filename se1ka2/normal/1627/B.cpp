#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

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

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        Graph g(n * m + 1);
        if(n % 2){
            if(m % 2){
                g.add_edge(n * m, (n / 2) * m + (m / 2));
            }
            else{
                g.add_edge(n * m, (n / 2) * m + (m / 2));
                g.add_edge(n * m, (n / 2) * m + (m / 2 - 1));
            }
        }
        else{
            if(m % 2){
                g.add_edge(n * m, (n / 2) * m + (m / 2));
                g.add_edge(n * m, (n / 2 - 1) * m + (m / 2));
            }
            else{
                g.add_edge(n * m, (n / 2) * m + (m / 2));
                g.add_edge(n * m, (n / 2) * m + (m / 2 - 1));
                g.add_edge(n * m, (n / 2 - 1) * m + (m / 2));
                g.add_edge(n * m, (n / 2 - 1) * m + (m / 2 - 1));
            }
        }
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                for(int i = 0; i < 4; i++){
                    int u = x + dx[i], v = y + dy[i];
                    if(u >= 0 && u < n && v >= 0 && v < m) g.add_edge(x * m + y, u * m + v);
                }
            }
        }
        vector<int> d = bfs(g, n * m);
        sort(d.begin(), d.begin() + n * m);
        for(int i = 0; i < n * m; i++) cout << d[i] + n / 2 + m / 2 - 1 << " ";
        cout << endl;
    }
}