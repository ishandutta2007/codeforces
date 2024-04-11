#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> P;

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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        Graph g(n);
        Graph r(n);
        int d[200005];
        for(int i = 0; i < n; i++) d[i] = 0;
        for(int i = 0; i < m; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            x--; y--;
            g.add_edge(x, y);
            r.add_edge(y, x);
            d[y]++;
        }
        int p[200005];
        for(int i = 0; i < n; i++) p[i] = -1;
        queue<int> que;
        for(int i = 0; i < n; i++){
            if(!d[i]){
                que.push(i);
                p[i] = 0;
            }
        }
        while(que.size()){
            int u = que.front();
            que.pop();
            for(int v : g.g[u]){
                d[v]--;
                if(d[v] == 0){
                    que.push(v);
                    for(int w : r.g[v]){
                        p[v] = max(p[v], (p[w] + 1) % 3);
                    }
                }
            }
        }
        int k = 0;
        for(int i = 0; i < n; i++){
            if(p[i] == 2) k++;
        }
        printf("%d\n", k);
        for(int i = 0; i < n; i++){
            if(p[i] == 2) printf("%d ", i + 1);
        }
        printf("\n");
    }
}