//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 3e3 + 9;
const int oo = 1 << 28;
int dis[Maxn][Maxn];
int vis[Maxn];
int Que[Maxn];
vector<int> al[Maxn];
int n,m;
void bfs(int v){
    memset(vis,0,sizeof vis);
    for(int i = 0; i < n;i++)
        dis[v][i] = oo;
    int bg = 0,ed = 0;
    Que[ed++] = v;
    vis[v] = 1;
    dis[v][v] = 0;
    while(bg != ed){
        int u = Que[bg++];
        for(int i = 0; i < al[u].size();i++){
            int next = al[u][i];
            if(!vis[next]){
                vis[next] = 1;
                dis[v][next] = dis[v][u] + 1;
                Que[ed++] = next;
            }
        }
    }
    return;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        al[--u].push_back(--v);
        al[v].push_back(u);
    }
    int s1,t1,l1,s2,t2,l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    s1--,t1--,s2--,t2--;
    for(int u = 0; u < n;u++){
        bfs(u);
    }
    if(dis[s1][t1] > l1 || dis[s2][t2] > l2){
        cout << -1 << endl;
        return 0;
    }
    int ans = dis[s1][t1] + dis[s2][t2];
    for(int u = 0; u < n;u++)
        for(int v = 0;v < n;v++){
            if(dis[s1][u] + dis[u][v] + dis[v][t1] <= l1 && dis[s2][u] + dis[u][v] + dis[v][t2] <= l2)
                ans = min(ans,dis[s1][u] + dis[u][v] + dis[v][t1] + dis[s2][u] + dis[v][t2]);
        }
    swap(s1,t1);
    for(int u = 0; u < n;u++)
        for(int v = 0;v < n;v++){
            if(dis[s1][u] + dis[u][v] + dis[v][t1] <= l1 && dis[s2][u] + dis[u][v] + dis[v][t2] <= l2)
                ans = min(ans,dis[s1][u] + dis[u][v] + dis[v][t1] + dis[s2][u] + dis[v][t2]);
        }
    ans = m - ans;
    cout << ans << endl;
    return 0;
}