#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
const LL INF = 1e16;
const int N = 300000 + 10;
typedef pair<LL,int> pii;
int n,m,k;
struct Edge {
    int v,w, id;
} e[N]; vector<Edge> g[N];
LL dis[N];int vis[N];
void dijkstra(int src) {
    for (int i = 0; i < N; i ++)
        dis[i] = INF, vis[i] = 0;
    dis[src] = 0;
    priority_queue< pii, vector<pii>, greater<pii> > que; que.push(make_pair(0,src));
    while (que.size()) {
        int se = que.top().second;
        que.pop();
        if (vis[se]) continue;
        vis[se] = 1;
        for (int i = 0; i < g[se].size(); i ++) {
            int nex = g[se][i].v;
            if (dis[nex] > dis[se] + g[se][i].w) {
                dis[nex] = dis[se] + g[se][i].w;
                que.push(make_pair(dis[nex], nex));
            }
        }
    }
}

int u[N],v[N],w[N];
vector<int> Del;
bool used[N];
void dfs(int u,int p) {
    used[u]=1;
    for(int i=0;i<g[u].size();i++) {
        if(g[u][i].v == p) continue;
        if(dis[u]+g[u][i].w == dis[g[u][i].v] && used[g[u][i].v]==0) {
            Del.push_back(g[u][i].id);
            dfs(g[u][i].v, u);
        }
    }
} 

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        g[u[i]].push_back((Edge){v[i],w[i],i});
        g[v[i]].push_back((Edge){u[i],w[i],i});
    }
    dijkstra(1);
    dfs(1,1);
    printf("%d\n", min(k,n-1));
    for(int i=0;i<min(k,n-1);i++) {
        printf("%d ", Del[i]);
    }
}