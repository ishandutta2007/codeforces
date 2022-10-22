#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;

const ll MOD = 998244353;

struct Graph
{
    int n;
    vector<vector<int>> g;
    
    Graph(){}
    
    Graph(int n) : n(n){
        g.resize(n);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

int d[2][200005];
int e[200005];
int dist[62][200005];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Graph g(n);
    Graph r(n);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        g.add_edge(a, b);
        r.add_edge(b, a);
    }
    for(int i = 0; i < n; i++) d[0][i] = d[1][i] = -1;
    d[0][0] = 0;
    priority_queue<P, vector<P>, greater<P>> que1;
    que1.push(P(0, 0));
    while(que1.size()){
        P p = que1.top();
        que1.pop();
        int u = p.second;
        int c = p.first;
        if(d[c % 2][u] < c) continue;
        for(int v : g.g[u]){
            if(c % 2){
                if(d[0][v] == -1 || d[0][v] > d[1][u] + 1){
                    d[0][v] = d[1][u] + 1;
                    que1.push(P(d[0][v], v));
                }
            }
            else{
                if(d[0][v] == -1 || d[0][v] > d[0][u]){
                    d[0][v] = d[0][u];
                    que1.push(P(d[0][v], v));
                }
            }
        }
        for(int v : r.g[u]){
            if(c % 2){
                if(d[1][v] == -1 || d[1][v] > d[1][u]){
                    d[1][v] = d[1][u];
                    que1.push(P(d[1][v], v));
                }
            }
            else{
                if(d[1][v] == -1 || d[1][v] > d[0][u] + 1){
                    d[1][v] = d[0][u] + 1;
                    que1.push(P(d[1][v], v));
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        e[i] = n;
        if(d[0][i] != -1) e[i] = min(e[i], d[0][i]);
        if(d[1][i] != -1) e[i] = min(e[i], d[1][i]);
    }
    for(int i = 0; i < 30; i++){
        for(int u = 0; u < n; u++) dist[i][u] = -1;
    }
    dist[0][0] = 0;
    priority_queue<PP, vector<PP>, greater<PP>> que2;
    que2.push(PP(0, P(0, 0)));
    while(que2.size()){
        PP pp = que2.top();
        que2.pop();
        int k = pp.second.first;
        int u = pp.second.second;
        int c = pp.first;
        if(dist[k][u] < c) continue;
        for(int v : g.g[u]){
            int l;
            if((e[u] + k) % 2) l = e[u] + k + 1 - e[v];
            else l = e[u] + k - e[v];
            if(l >= 30) continue;
            if(dist[l][v] == -1 || dist[l][v] > dist[k][u] + 1){
                dist[l][v] = dist[k][u] + 1;
                que2.push(PP(dist[l][v], P(l, v)));
            }
        }
        for(int v : r.g[u]){
            int l;
            if((e[u] + k) % 2) l = e[u] + k - e[v];
            else l = e[u] + k + 1 - e[v];
            if(l >= 30) continue;
            if(dist[l][v] == -1 || dist[l][v] > dist[k][u] + 1){
                dist[l][v] = dist[k][u] + 1;
                que2.push(PP(dist[l][v], P(l, v)));
            }
        }
    }
    ll p[62];
    p[0] = 1;
    for(int i = 1; i <= 60; i++) p[i] = p[i - 1] * 2;
    if(e[n - 1] < 25){
        ll ans = p[60];
        for(int i = 0; i < 30; i++){
            if(dist[i][n - 1] != -1){
                ans = min(ans, p[e[n - 1] + i] - 1 + dist[i][n - 1]);
            }
        }
        cout << ans % MOD << endl;
    }
    else{
        ll t = 1;
        for(int i = 0; i < e[n - 1]; i++) t = t * 2 % MOD;
        cout << (t + dist[0][n - 1] + MOD - 1) % MOD << endl;
    }
}