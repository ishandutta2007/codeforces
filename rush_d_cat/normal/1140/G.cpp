#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
struct Edge {
    int v; LL w0,w1;
};
int n,sz[N],conquered[N],mx[N];
LL bridge[N];
vector<int> comp[N],compPath[N]; 
vector<Edge> g[N];

void dfs_miao(int id,int u,int p){
    comp[id].push_back(u); sz[u]=1; mx[u]=0;
    for(auto e: g[u]) {
        if(e.v!=p && conquered[e.v]==0){
            dfs_miao(id,e.v,u);
            sz[u]+=sz[e.v];
            mx[u]=max(mx[u],sz[e.v]);
        }
    }
}
int getRoot(int id,int u){
    dfs_miao(id,u,u);
    int mn=N,rt=-1;
    for(int i=0;i<comp[id].size();i++){
        compPath[comp[id][i]].push_back(id);
        mx[comp[id][i]] = max(mx[comp[id][i]], sz[u]-sz[comp[id][i]]);
        if (mx[comp[id][i]] < mn) {
            mn = mx[comp[id][i]], rt=comp[id][i];
        }
    }
    return rt;
}
map<int,LL> dp[N][2];
void cacDP(int id,int u,int p) {
    for(auto e: g[u]) {
        if(e.v == p || conquered[e.v]) continue;
        int v=e.v;
        dp[id][0][v*2-1]=dp[id][0][u*2-1] + e.w0;
        dp[id][1][v*2-1]=dp[id][1][u*2-1] + e.w0;
        dp[id][0][v*2]=dp[id][0][u*2] + e.w1;
        dp[id][1][v*2]=dp[id][1][u*2] + e.w1;

        dp[id][0][v*2-1]=min(dp[id][0][v*2-1], dp[id][0][v*2] + bridge[v]);
        dp[id][1][v*2-1]=min(dp[id][1][v*2-1], dp[id][1][v*2] + bridge[v]);
        dp[id][0][v*2]=min(dp[id][0][v*2], dp[id][0][v*2-1] + bridge[v]);
        dp[id][1][v*2]=min(dp[id][1][v*2], dp[id][1][v*2-1] + bridge[v]);
        cacDP(id,e.v,u);
    }
}
int tot=0;
void divide_and_conquere(int u){
    int now = (++tot);
    u=getRoot(tot,u); conquered[u]=1;
    dp[tot][1][u*2-1] = dp[tot][0][u*2] = bridge[u];

    cacDP(tot,u,u);
    for(auto e: g[u]){
        if(!conquered[e.v]){
            divide_and_conquere(e.v);
        }
    }
}

struct Nod{
    int id; LL dis;
    bool operator<(const Nod&o)const{
        return dis>o.dis;
    }
};
struct Dijkstra{
    vector< pair<int,LL> > gragh[N];
    LL dis[N]; 
    void dijkstra() {
        for(int i=1;i<=n;i++){
            gragh[0].push_back(make_pair(i,bridge[i]));
        }
        for(int i=1;i<=n;i++){
            for(auto e: g[i]){
                gragh[i].push_back(make_pair(e.v,e.w0+e.w1));
            }
        }
        priority_queue<Nod> q;
        memset(dis,-1,sizeof(dis));
        q.push((Nod){0,0}); dis[0]=0;
        while(q.size()){
            Nod tmp=q.top(); q.pop();
            if(dis[tmp.id] != -1 && dis[tmp.id] < tmp.dis) continue;
            for(int i=0;i<gragh[tmp.id].size();i++){
                int v=gragh[tmp.id][i].first;
                if(dis[v]==-1 || dis[tmp.id]+gragh[tmp.id][i].second<dis[v]){
                    dis[v]=dis[tmp.id]+gragh[tmp.id][i].second;
                    q.push((Nod){v,dis[v]});
                }
            }
        }
        for(int i=1;i<=n;i++){
            bridge[i]=dis[i];
        }
    }
} saber;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&bridge[i]);
    }
    for(int i=1;i<n;i++){
        int u,v;LL w0,w1;
        scanf("%d%d%lld%lld",&u,&v,&w0,&w1);
        g[u].push_back((Edge){v,w0,w1});
        g[v].push_back((Edge){u,w0,w1});
    }
    saber.dijkstra();
    //for(int i=1;i<=n;i++)
    //    printf("bridge[%d]=%lld\n", i, bridge[i]);
    divide_and_conquere(1);
    int q; scanf("%d",&q);
    while(q--) {
        int u,v; scanf("%d%d",&u,&v); 
        int lef=0,rig=min(compPath[(u+1)/2].size(), compPath[(v+1)/2].size());
        while(rig-lef>1){
            int mid=(lef+rig)>>1;
            if(compPath[(u+1)/2][mid] == compPath[(v+1)/2][mid])
                lef=mid;
            else
                rig=mid;
        }
        int id = compPath[(u+1)/2][lef];
        //printf("id = %d\n", id);
        //for(auto x: comp[id])
        //    printf("%d ", x); printf("\n");
        LL ans = min(dp[id][0][u] + dp[id][0][v], dp[id][1][u] + dp[id][1][v]);
        //printf("(%lld %lld) (%lld %lld)\n", dp[id][u][0],dp[id][v][0],dp[id][u][1],dp[id][v][1]);
        printf("%lld\n", ans);
    }
}