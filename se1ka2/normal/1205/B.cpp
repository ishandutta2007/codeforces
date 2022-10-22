#include <algorithm>
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

int cycle(int r, int n, Graph &g){
    int d[130];
    int p[130];
    for(int i = 0; i < n; i++) d[i] = p[i] = -1;
    d[r] = 0;
    queue<int> que;
    que.push(r);
    while(que.size()){
        int u = que.front();
        que.pop();
        for(int v : g.g[u]){
            if(v == p[u]) continue;
            if(d[v] >= 0) return d[u] + d[v] + 1;
            d[v] = d[u] + 1;
            p[v] = u;
            que.push(v);
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    ll a[100005];
    int b[62]{0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < 60; j++){
            b[j] += (a[i] >> j) & 1;
        }
    }
    for(int j = 0; j < 60; j++){
        if(b[j] >= 3){
            cout << 3 << endl;
            return 0;
        }
    }
    sort(a, a + n, greater<ll>());
    while(n > 0 && a[n - 1] == 0) n--;
    Graph g(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(a[i] & a[j]) g.add_edge(i, j);
        }
    }
    int ans = -1;
    for(int r = 0; r < n; r++){
        int c = cycle(r, n, g);
        if(c == -1) continue;
        if(ans == -1 || c < ans) ans = c;
    }
    cout << ans << endl;
}