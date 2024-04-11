#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <stack>
using namespace std;
const int N = 200000 + 10;
vector<int> g[N], bcc[N], tree[N];


struct BCC {
    int pre[N], low[N], iscut[N], bccno[N];
    int dfs_clock, bcc_cnt;
    stack<int> S;
    
    int dfs(int u, int p) 
    {
        int lowu = pre[u] = ++ dfs_clock; S.push(u); low[u]=lowu;
        map<int,int> vis; vis.clear();

        for(auto v: g[u]) {
            //printf("%d->%d\n", u,v);
            vis[v]++;
            if(v==p && vis[v]==1)continue;

            int fg=pre[v];
            if(pre[v]==0){
                dfs(v,u); 
            } 
            lowu=min(lowu,low[v]); low[u]=lowu;

        }
        if(pre[u]==lowu){
            ++bcc_cnt;
            while(S.size()){
                int tmp=S.top(); S.pop(); bccno[tmp]=bcc_cnt;
                if(tmp==u) {
                    break;
                }
            }
        }

        return low[u]=lowu;
    }

    void Excalibur(int n) 
    {
        memset(pre, 0, sizeof(pre));
        memset(low, 0, sizeof(low));
        memset(iscut, 0, sizeof(iscut));
        memset(bccno, 0, sizeof(bccno));
        dfs_clock = bcc_cnt = 0;
        
        for (int i = 1; i <= n; i ++) {
            if (pre[i] == 0)
                dfs(i, -1);
        }   
    }
} Saber;

int n,m,q,u[N],v[N];
int par[N][20],dep[N],sum[N],tot[N];
void dfs(int u,int p) {
    par[u][0]=p; dep[u]=dep[p]+1;
    for(auto v: tree[u]){
        if(v==p)continue;
        //printf("%d->%d\n", u,v);
        dfs(v,u);
    }
}
bool solved[N];
void solve(int u,int p){
    if(solved[u])return;
    solved[u]=1;
    for(auto v: tree[u]){
        if(v==p)continue;
        solve(v,u);
        sum[u]+=sum[v];
        tot[u]+=tot[v];
    }
    //printf("u=%d, sum=%d, tot=%d\n", u,sum[u],tot[u]);
    if(abs(sum[u]) != abs(tot[u]) && u!=1) {
        printf("No\n"); exit(0);
    }
}
void init(){
    for(int i=1;i<20;i++)
        for(int j=1;j<=Saber.bcc_cnt;j++)
            par[j][i]=par[par[j][i-1]][i-1];
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=19;i>=0;i--)
        if(d>>i&1)u=par[u][i];
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i])
            u=par[u][i],v=par[v][i];
    }
    return par[u][0];
}
int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]); 
        if(u[i]>v[i]) swap(u[i],v[i]);
        g[u[i]].push_back(v[i]); g[v[i]].push_back(u[i]);
    }
    Saber.Excalibur(n);
    for(int i=1;i<=m;i++){
        if (Saber.bccno[u[i]] == Saber.bccno[v[i]]) continue;
        tree[ Saber.bccno[u[i]] ].push_back( Saber.bccno[v[i]] );
        tree[ Saber.bccno[v[i]] ].push_back( Saber.bccno[u[i]] );
    }
    for(int i=1;i<=Saber.bcc_cnt;i++){
        if(par[i][0]==0)
            dfs(i,i); 
    }
    init();
    //for(int i=1;i<=n;i++)
    //    printf("bcc[%d]=%d\n", i,Saber.bccno[i]);
    for(int i=1;i<=q;i++){
        int u,v; scanf("%d%d",&u,&v);
        u = Saber.bccno[u];
        v = Saber.bccno[v];
        if (u != v) {
            //printf("u=%d, v=%d\n",u,v);
            sum[u]++;
            sum[v]--;
            int l = lca(u,v);
            //printf("lca(%d,%d)=%d\n", u,v,l);
            tot[u]++, tot[v]++, tot[l]-=2;
        }
    }
    for(int i=1;i<=Saber.bcc_cnt;i++)
        if(!solved[i])
            solve(i,i);
    printf("Yes\n");
}