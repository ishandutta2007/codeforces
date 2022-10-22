#include<bits/stdc++.h>
using namespace std;
const int maxn = 610;
const long long inf = 1e18;
long long ans[maxn][maxn];
long long dis[maxn];
int vis[maxn];
vector<pair<int,int>> g[maxn];
void dij(int u, int n){
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int> > > q;
    for (int i = 0; i < n; i++) vis[i] = 0;
    for (int i = 0; i < n; i++) dis[i] = inf;
    for (auto e : g[u]) dis[e.first] = e.second;
    for (int i = 0; i < n; i++) q.push(make_pair(dis[i], i));
    while (!q.empty()) {
        auto x = q.top(); q.pop();
        //if (u == 1) printf("CASE %d %lld\n", x.second, dis[x.second]); 
        if (vis[x.second]) continue;
        int v = x.second; vis[v] = 1;
        for (auto e : g[v]) {
            int nex = (e.first + dis[v]) % n;
            if (dis[v] + e.second < dis[nex]) {
                dis[nex] = dis[v] + e.second;
                q.push(make_pair(dis[nex], nex));
            }
        }
        for (int i = 1; i < n; i++) {
            int nex = (v + i) % n;
            if (dis[v] + i < dis[nex]) {
                dis[nex] = dis[v] + i;
                q.push(make_pair(dis[nex], nex));
            }
        }
    }
    for (int i = 0; i < n; i++) if (i != u) ans[u][i] = dis[i];
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j) ans[i][j] = inf;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(make_pair(b, c));
    }
    for (int i = 0; i < n; i++) dij(i, n);
    for (int i = 0; i < n; i++, puts(""))
        for (int j = 0; j < n; j++) printf("%lld ", ans[i][j]);
    return 0;
}