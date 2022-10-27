#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 800000+10;
const LL INF=1e18;

int n,m,u[N],v[N],w[N];
int dfnL[N],dfnR[N],who[N],moment;
LL dis[N],lazy[N],val[N];
LL disToRoot[N];
vector< pair<int,int> > g[N];
LL par[N][20],dep[N];

void dfs(int u,int p) {
    dfnL[u]=++moment; who[moment]=u;
    dep[u]=dep[p]+1;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i].first; 
        par[v][0]=u; 
        dis[v]=dis[u]+g[u][i].second; 
        dfs(v,u);
    }
    dfnR[u]=moment;
}
void push_down(int rt) {
    if(lazy[rt]) {
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        val[rt<<1]+=lazy[rt];
        val[rt<<1|1]+=lazy[rt];
        lazy[rt]=0;
    }
}
void build(int l,int r,int rt) {
    if(l==r) {
        val[rt]=dis[who[l]]+disToRoot[who[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    val[rt]=min(val[rt<<1],val[rt<<1|1]);
}
LL queryMin(int l,int r,int rt,int L,int R) {
    if(L<=l&&r<=R) return val[rt];
    push_down(rt);
    int mid=(l+r)>>1; LL ans=1e16;
    if(L<=mid) ans=min(ans,queryMin(l,mid,rt<<1,L,R));
    if(R >mid) ans=min(ans,queryMin(mid+1,r,rt<<1|1,L,R));
    return ans;
}
void update(int l,int r,int rt,int L,int R,LL x) {
    if(L<=l&&r<=R) {
        lazy[rt]+=x;
        val[rt] +=x;
        return;
    }
    push_down(rt);
    int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,rt<<1,L,R,x);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R,x);
    val[rt]=min(val[rt<<1],val[rt<<1|1]);
}
bool ispar(int u, int v) {
    int k = dep[v]-dep[u]; if(k<0) return 0;
    int cur=v; LL ans=0;
    for(int i=0;i<20;i++) {
        if((k>>i)&1) cur=par[cur][i];
    }
    return cur == u;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++) {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        g[u[i]].push_back(make_pair(v[i],w[i]));
    }
    for(int i=n;i<2*n-1;i++) {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        disToRoot[u[i]] = w[i];
    }
    dfs(1,1);
    for(int i=1;i<20;i++) {
        for(int j=1;j<=n;j++){
            par[j][i]=par[par[j][i-1]][i-1];
        }
    }
    build(1,n,1);

    for(int i=1;i<=m;i++) {
        int op,x,y;scanf("%d%d%d",&op,&x,&y);
        if(op==1) {
            if(x<n) {
                update(1,n,1,dfnL[v[x]],dfnR[v[x]],y-w[x]);
                w[x] = y;
            } else {
                update(1,n,1,dfnL[u[x]],dfnL[u[x]],y-disToRoot[u[x]]);
                disToRoot[u[x]]=y;
            }
        }
        if(op==2) {
            LL ans = queryMin(1,n,1,dfnL[x],dfnR[x]) 
            - ( queryMin(1,n,1,dfnL[x],dfnL[x]) - disToRoot[x] )
            + ( queryMin(1,n,1,dfnL[y],dfnL[y]) - disToRoot[y] );

            if(ispar(x,y)) {
                ans = min(ans,
                (queryMin(1,n,1,dfnL[y],dfnL[y])-disToRoot[y]) - (queryMin(1,n,1,dfnL[x],dfnL[x])-disToRoot[x])
                    );
            }

            printf("%lld\n", ans);
        }
    }
}