#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
const int N=100000+10;
int n,m;
struct Edge{
    int u,v,w,id;
    bool operator<(const Edge&o)const{
        return w>o.w;
    }
} e[N];
int vis[N],rev[N];
vector<int> g[N];

bool ok=1;
void dfs(int u){
    vis[u]=1; 
    for(auto v:g[u]){
        if(vis[v]==1) ok=0;
        if(vis[v]==0) dfs(v);
    }
    vis[u]=2;
}
bool chk(int x){
    for(int i=1;i<=n;i++) vis[i]=0,g[i].clear();
    for(int i=1;i<=x;i++){
        g[e[i].u].push_back(e[i].v);
    }

    ok=1;
    for(int i=1;i<=n;i++){
        if(vis[i]==0) dfs(i);
    }
    return ok;
}
int in[N],bfn[N],C;
void top(int x){
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1;i<=x;i++){
        g[e[i].u].push_back(e[i].v); in[e[i].v]++;
    }
    queue<int> q; 
    for(int i=1;i<=n;i++){
        if(in[i]==0) q.push(i);
    }
    while(q.size()){
        int u=q.front(); q.pop(); bfn[u]=++C;
        for(auto v: g[u]){
            in[v]--; 
            if(in[v]==0) q.push(v);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w), e[i].id=i;
    }
    sort(e+1,e+1+m); e[m+1].w=0;
    int L=1,R=m+1;
    while(R-L>1){
        int mid=(L+R)>>1;
        if(chk(mid)){
            L=mid;
        } else {
            R=mid;
        }
    }
    top(L);
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(i>L && bfn[e[i].u]>bfn[e[i].v]) rev[e[i].id]=1, cnt++;
    }
    printf("%d %d\n", e[L+1].w, cnt);
    for(int i=1;i<=m;i++)
        if(rev[i]==1)printf("%d ", i);
}
/*
5 -> 2 -> 1
 |   |
  4 - 3
*/