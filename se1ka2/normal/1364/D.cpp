#include <algorithm>
#include <iostream>
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
    int n, m, k;
    cin >> n >> m >> k;
    Graph g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g.add_edge(u, v);
        g.add_edge(v, u);
    }
    int d[100002], par[100002];
    fill(d, d + n, -1);
    fill(par, par + n, -1);
    queue<int> que;
    d[0] = 0;
    que.push(0);
    vector<int> v1, v2;
    bool f = false;
    int nxt[100005];
    fill(nxt, nxt + n, -1);
    int u;
    while(que.size() && !f){
        u = que.front();
        que.pop();
        for(int v : g.g[u]){
            if(v == par[u]) continue;
            if(d[v] == -1){
                d[v] = d[u] + 1;
                par[v] = u;
                que.push(v);
            }
            else{
                f = true;
                nxt[u] = v;
                if(d[u] < d[v]){
                    nxt[v] = par[v];
                    v = par[v];
                }
                while(u != v){
                    nxt[par[u]] = u;
                    nxt[v] = par[v];
                    u = par[u];
                    v = par[v];
                }
                break;
            }
        }
    }
    if(!f){
        cout << 1 << endl;
        k = (k + 1) / 2;
        int c = 0;
        for(int i = 0; i < n; i++){
            c += d[i] % 2;
        }
        int j;
        if(c >= k) j = 1;
        else j = 0;
        c = 0;
        for(int i = 0; i < n; i++){
            if(c == k) continue;
            if(d[i] % 2 == j){
                printf("%d ", i + 1);
                c++;
            }
        }
        cout << endl;
        return 0;
    }
    int l[100005];
    fill(l, l + n, -1);
    int c = 0;
    while(l[u] == -1){
        l[u] = c;
        u = nxt[u];
    }
    int e = 0;
    int s = u;
    while(true){
        int c = -1;
        for(int v : g.g[u]){
            if(nxt[u] != v && nxt[v] != -1 && nxt[v] != u){
                c = max(c, (l[v] + n - l[u]) % n);
            }
        }
        for(int v : g.g[u]){
            if((l[v] + n - l[u]) % n == c){
                int w = nxt[u];
                while(w != v){
                    int x = w;
                    w = nxt[w];
                    nxt[x] = -1;
                }
                nxt[u] = v;
                e = 0;
                s = u;
                break;
            }
        }
        u = nxt[u];
        if(s == u) break;
    }
    e = 0;
    for(int i = 0; i < n; i++){
        if(nxt[i] != -1) e++;
    }
    if(e <= k){
        cout << 2 << endl;
        cout << e << endl;
        for(int i = 0; i < e; i++){
            printf("%d ", u + 1);
            u = nxt[u];
        }
        cout << endl;
    }
    else{
        cout << 1 << endl;
        for(int i = 0; i < k; i++){
            if(i % 2 == 0) printf("%d ", u + 1);
            u = nxt[u];
        }
        cout << endl;
    }
}