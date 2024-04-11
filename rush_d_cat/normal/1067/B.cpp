#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n,k,deg[N],dep[N],par[N];
vector<int> g[N];

void dfs(int u,int p){
    dep[u]=dep[p]+1; par[u]=p;
    for(auto v:g[u]){
        if(p==v)continue;
        dfs(v,u);
    }
}
int getRoot() {
    int mx=0,id=0;
    for(int i=1;i<=n;i++){
        if(dep[i]>mx) {
            mx=dep[i]; id=i;
        }
    }
    //printf("mx=%d\n", mx);
    if(mx%2==0) {
        printf("NO\n"); exit(0);
    }
    for(int i=1;i<=mx/2;i++){
        id=par[id];
    }
    return id;
}
int dis[N];
void bfs(int rt){
    //printf("rt=%d\n", rt);
    queue<int> q;
    for(int i=1;i<=n;i++)dis[i]=-1;
    q.push(rt);dis[rt]=0;
    int mx=0; for(int i=1;i<=n;i++)mx=max(mx,dep[i]); mx=(mx+1)/2;
    int deep=0, cnt=0;
    //printf("rt=%d\n", rt);
    while(q.size()){
        deep++; 
        vector<int> vec;vec.clear();
        while(q.size()){
            int u=q.front(); q.pop(); cnt++;
            int son=0;
            for(auto v:g[u]){
                if(dis[v]!=-1)continue;
                dis[v]=dis[u]+1; vec.push_back(v); son++;
            }
            if(son<3 && deep!=mx) {
                printf("NO\n");exit(0);
            }
        }
        for(auto x:vec) q.push(x);
        if(deep==mx)break;
    }
    if(deep==k+1 && deep==mx && cnt==n)printf("YES\n");
    else printf("NO\n");
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        deg[u]++, deg[v]++;
        g[u].push_back(v); g[v].push_back(u);
    }
    int rt=0;
    for(int i=1;i<=n;i++){
        if(deg[i]==1) {
            rt=i; break;
        }
    }
    //printf("rt=%d\n", rt);
    dfs(rt,rt);
    rt=getRoot();
    //printf("rt=%d\n", rt);
    bfs(rt);
}