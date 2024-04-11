#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int INF = 100000000;

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

vector<int> Dijkstra(Graph &g, int s){
    int n = g.n;
    vector<int> d(n);
    fill(d.begin(), d.end(), INF);
    d[s] = 0;
    queue<int> que;
    que.push(s);
    while(que.size()){
        int u = que.front();
        que.pop();
        for(int v : g.g[u]){
            if(d[v] == INF){
                d[v] = d[u] + 1;
                que.push(v);
            }
        }
    }
    return d;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[200005];
    for(int i = 0; i < k; i++){
        scanf("%d", &a[i]);
        a[i]--;
    }
    Graph g(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g.add_edge(x, y);
        g.add_edge(y, x);
    }
    vector<int> d1 = Dijkstra(g, 0);
    vector<int> d2 = Dijkstra(g, n - 1);
    P p[200005];
    for(int i = 0; i < k; i++) p[i] = P(d1[a[i]], d2[a[i]]);
    sort(p, p + k);
    int ans = 0;
    for(int i = 1; i < k; i++){
        ans = max(ans, min(d2[0], p[i - 1].first + p[i].second + 1));
    }
    cout << ans << endl;
}