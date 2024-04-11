#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const LL INF = 2e18;
const int N = 200000+100;
typedef pair<LL, int> pii;
int vis[N], n, m; 
LL dis[N], a[N], u, v, w;
vector< pii > g[N];
void dijkstra(int s) {
    for (int i = 0; i < N; i ++) dis[i] = INF;
    dis[s] = 0;
    priority_queue< pii, vector<pii>, greater<pii> > que; que.push(make_pair(0,s));
    while (que.size()) {
        int now = que.top().second; LL val = que.top().first; que.pop(); 
        if (val != dis[now]) continue;
        for (int i = 0; i < g[now].size(); i ++) {
            if (dis[now] + g[now][i].first < dis[g[now][i].second]) {
                dis[g[now][i].second] = dis[now] + g[now][i].first;
                que.push(make_pair(dis[g[now][i].second], g[now][i].second));
            }
        }
    }
}   
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        scanf("%lld %lld %lld", &u, &v, &w);
        g[u].push_back(make_pair(2L*w, v));
        g[v].push_back(make_pair(2L*w, u));
    }
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
        g[0].push_back(make_pair(a[i], i));
    }
    dijkstra(0);
    for (int i = 1; i <= n; i ++) {
        printf("%lld\n", dis[i]);
    }
}