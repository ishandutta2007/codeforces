#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N=2000000+10;
typedef long long LL;
int n,m,deg[N],par[N],vis[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
int head[N<<1],edgeCnt;
struct Edge {
    int v,nex,type,fg;
} edge[N<<1];
void addEdge(int u,int v,int type){
    edge[edgeCnt].v=v,edge[edgeCnt].type=type,edge[edgeCnt].nex=head[u];
    head[u]=edgeCnt++;
}
int vec[N], tot;
vector<int> ans;
vector< pair<int,int> > res;
void EulerPath(int u){
    //printf("EulerPath %d\n", u);
    tot = 0; 
    vec[++tot]=u;
    ans.clear();
    while(tot) {
        int u=vec[tot];
        if(head[u]==-1) {
            tot--;
            ans.push_back(u);
            continue;
        }
        int v=edge[head[u]].v;
        if(edge[head[u]].fg) {
            head[u] = edge[head[u]].nex;
            continue;
        }
        edge[head[u]].fg = edge[head[u]^1].fg = 1;
        vec[++tot] = v;
    }
    bool fg=0;
    for(int i=(int)ans.size()-1;i>=1;i--){
        //printf("# %d %d\n", ans[i],ans[i-1]);
        if(i==1) fg=0;
        if(ans[i-1]==0) fg=0;
        if(i>=2 && ans[i-2]==0) fg=0;
        if(fg==0){
            if(ans[i]!=0 && ans[i-1] != 0)
                res.push_back(make_pair(ans[i], ans[i-1]));
        }
        fg ^= 1;
    }
}
int main() {
    memset(head,-1,sizeof(head));
    for(int i=0;i<N;i++) par[i]=i;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        addEdge(u,v,1); addEdge(v,u,1);
        deg[u]++, deg[v]++;
        par[find(u)]=find(v);
    }
    for(int i=1;i<=n;i++){
        if(deg[i]&1) {
            addEdge(0,i,0); addEdge(i,0,0);
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[find(i)]==0) {
            EulerPath(i); vis[find(i)]=1;
        }
    }
    printf("%d\n", res.size());
    for(int i=0;i<res.size();i++){
        printf("%d %d\n", res[i].first, res[i].second);
    }
}