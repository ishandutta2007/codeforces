#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 200000+10;
const LL INF = 1e16;
struct Edge {
    int u,v,id,used;
    LL w,c;
    bool operator < (const Edge & o) const {
        return w < o.w; 
    }
} e[N];
int n,m; LL s;
int son[N],par[N],len[N],dep[N],top[N],sz[N],fa[N];
int dfn[N],who[N],moment;
vector< pair<int,LL> > g[N];
void pre(int u,int p) {
    dep[u]=dep[p]+1;sz[u]=1;par[u]=p;
    int mx=-1,hson=-1;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i].first; 
        if (v==p) continue;
        len[v] = g[u][i].second;
        pre(v,u);
        sz[u]+=sz[v];
        if(sz[v]>mx) {
            mx=sz[v], hson=v;
        }
    }
    son[u]=hson;
}
void dfs(int u,int p) {
    top[u]=p;dfn[u]=++moment;who[moment]=u;
    if(son[u]!=-1)dfs(son[u],p);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first; if(v!=par[u]&&v!=son[u]) dfs(v,v);
    }
}
LL mx[N<<2],ps[N<<2];
void build(int l,int r,int rt) {
    if(l==r) {
        mx[rt]=len[who[l]];
        ps[rt]=l;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    ps[rt]=(mx[rt<<1]>mx[rt<<1|1]) ? ps[rt<<1] : ps[rt<<1|1];
}
pair<int,int> query(int l,int r,int rt,int L,int R) {
    if(L<=l&&r<=R) return make_pair(mx[rt], ps[rt]);
    int mid=(l+r)>>1;
    pair<int,int> ans=make_pair(0,0),tmp;
    if (L<=mid) {
        tmp=query(l,mid,rt<<1,L,R);
        if(tmp>ans) ans=tmp;
    }
    if (R >mid) {
        tmp=query(mid+1,r,rt<<1|1,L,R);
        if(tmp>ans) ans=tmp;
    }
    return ans;
}
pair<int,int> cac_path(int u,int v) {
    pair<int,int> tmp,ans=make_pair(0,0);
    while(top[u]!=top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        tmp=query(1,n,1,dfn[top[u]],dfn[u]);
        if(tmp>ans) ans=tmp;
        u=par[top[u]];
    }
    if(u==v) return ans;
    if(dep[u]>dep[v]) swap(u,v);
    tmp=query(1,n,1,dfn[son[u]],dfn[v]);
    if(tmp>ans) ans=tmp;
    return ans;
}
int find(int x) {
    return fa[x]==-1?x:fa[x]=find(fa[x]);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%lld",&e[i].w);
    for(int i=1;i<=m;i++) scanf("%lld",&e[i].c);
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&e[i].u,&e[i].v);
        e[i].id=i;e[i].used=0;
    }
    scanf("%lld",&s);

    LL sum=0;
    sort(e+1,e+1+m);
    for(int i=1;i<=n;i++) fa[i]=-1;
    for(int i=1;i<=m;i++) {
        int pu=find(e[i].u);
        int pv=find(e[i].v);
        if (pu!=pv){
            //printf("%d->%d\n", e[i].u,e[i].v);
            g[e[i].u].push_back(make_pair(e[i].v,e[i].w));
            g[e[i].v].push_back(make_pair(e[i].u,e[i].w));
            fa[pv]=pu;
            sum+=e[i].w;
            e[i].used=1;
        }
    }

    pre(1,1); dfs(1,1);
    build(1,n,1);

    LL ans=INF,bst=-1,ban=-1;
    for(int i=1;i<=m;i++) {
        if(e[i].used==1) {
            LL tmp=sum-s/e[i].c;
            if(tmp<ans) {
                ans=tmp; bst=e[i].id; ban=-1;
            }
        } else {
            int mx = cac_path(e[i].u, e[i].v).first;
            LL tmp=sum-mx+e[i].w-s/e[i].c;
            if(tmp<ans) {
                ans=tmp; bst=e[i].id; 
                ban = cac_path(e[i].u, e[i].v).second;
            } 
       }
    }
    printf("%lld\n", ans);
    for(int i=1;i<=m;i++) {
        bool ok=0;
        if(e[i].id == bst) {
            e[i].w -= s/e[i].c; ok=1;
        } 
        if(e[i].used==1) {
            if(dfn[e[i].u]<dfn[e[i].v]) swap(e[i].u,e[i].v);
            if(dfn[e[i].u]==ban) ok=0;
            else ok=1;
        }
        if (ok) printf("%d %lld\n", e[i].id, e[i].w);
    } 
}