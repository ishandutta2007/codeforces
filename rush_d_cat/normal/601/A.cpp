#include <iostream>
using namespace std;
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 2002;
const int inf = 10000007;
int vis[MAXN], dis[MAXN], mp[MAXN][MAXN];
int n, m;
int dijkstra(int s) {
    for(int i=0;i<MAXN;i++) dis[i] = inf,vis[i] = 0;
    int cur = s;
    dis[cur] = 0;
    vis[cur] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(!vis[j]&&dis[cur]+mp[cur][j]<dis[j]) {
                dis[j]=dis[cur]+mp[cur][j];
            }
        }
        int minc = inf;
        for(int j=1;j<=n;j++) {
            if(!vis[j]&&dis[j]<minc)
                minc=dis[cur=j];
        }   
        vis[cur]=1;
    }
    return dis[n];
}
int main() 
{
    scanf("%d %d", &n, &m);
    int i, j;
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) mp[i][j]=inf;
    for(i=1;i<=m;i++) 
    {
        int u, v, w;
        scanf("%d %d", &u, &v);
        mp[u][v] = mp[v][u] = 1;
    }
    int res=dijkstra(1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(mp[i][j] == inf) mp[i][j] = 1;
            else mp[i][j] = inf;
        }
    }
    res = max(res, dijkstra(1));
    printf("%d\n", res==inf?-1:res);
}