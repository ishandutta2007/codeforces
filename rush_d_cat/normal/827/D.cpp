#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 2000000+10;
const int INF = 1000000007;

struct Edge {
    int u, v, w;
    int id, used;
    bool operator < (const Edge & o) const {
        return w < o.w;
    }
} e[N];

int n, m;
int fa[N], par[N], len[N], son[N];
int sz[N], dep[N];
int top[N];
int dfn[N], who[N], moment;
vector< pair<int,int> > g[N];
int find(int x) {
    return fa[x] == -1 ? x: fa[x]=find(fa[x]);
}
void pre(int u,int p) {
    dep[u] = dep[p] + 1; par[u] = p; sz[u] = 1;
    int mx = -1, hson = -1;
    for (int i=0;i<g[u].size();i++) {
        int v = g[u][i].first;
        if (v == p) continue;
        len[v] = g[u][i].second;
        pre(v, u);
        sz[u] += sz[v];
        if (sz[v] > mx) {
            mx = sz[v];
            hson = v;
        }
    }
    son[u] = hson;
}
void dfs(int u,int p) {
    top[u]=p;
    dfn[u]=++moment; who[moment]=u;
    if(son[u]!=-1) {
        dfs(son[u],p);
    }
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i].first;
        if (v==son[u]||v==par[u]) continue;
        dfs(v,v);
    }
}       
struct Data {
    int Max, Min;
    int lazy;
} nod[N<<2];
void push_up(int rt) {
    nod[rt].Max = max(nod[rt<<1].Max, nod[rt<<1|1].Max);
    nod[rt].Min = min(nod[rt<<1].Min, nod[rt<<1|1].Min);
}
void push_down(int rt) {
    if (nod[rt].lazy) {
        nod[rt<<1].lazy = min(nod[rt<<1].lazy, nod[rt].lazy);
        if (nod[rt<<1].lazy == 0) nod[rt<<1].lazy = nod[rt].lazy;

        nod[rt<<1|1].lazy = min(nod[rt<<1|1].lazy, nod[rt].lazy);
        if (nod[rt<<1|1].lazy == 0) nod[rt<<1|1].lazy = nod[rt].lazy;
        
        nod[rt<<1].Min = min(nod[rt<<1].Min, nod[rt].lazy);
        nod[rt<<1|1].Min = min(nod[rt<<1|1].Min, nod[rt].lazy);
        nod[rt].lazy = 0;
    }
}
void build(int l,int r,int rt) {
    if (l==r) {
        nod[rt].Max = nod[rt].Min = len[who[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    push_up(rt);
}
int queryMax(int l,int r,int rt,int L,int R) {
    if (L<=l&&r<=R) return nod[rt].Max;
    push_down(rt);
    int mid=(l+r)>>1;
    int ans=0;
    if (L<=mid) ans=max(ans,queryMax(l,mid,rt<<1,L,R)); 
    if (R >mid) ans=max(ans,queryMax(mid+1,r,rt<<1|1,L,R));
    return ans;
}
int queryMin(int l,int r,int rt,int pos) {
    if(l==r) return nod[rt].Min;
    push_down(rt);
    int mid=(l+r)>>1;
    if (pos<=mid) return queryMin(l,mid,rt<<1,pos);
    else return queryMin(mid+1,r,rt<<1|1,pos);
}
void update(int l,int r,int rt,int L,int R,int x) {
    if(L<=l&&r<=R) {
        if (nod[rt].lazy==0) 
            nod[rt].lazy = x;
        else 
            nod[rt].lazy = min(nod[rt].lazy, x);
        nod[rt].Min = min(nod[rt].Min, x);
        return;
    }
    push_down(rt);
    int mid=(l+r)>>1;
    if (L<=mid) update(l,mid,rt<<1,L,R,x);
    if (R >mid) update(mid+1,r,rt<<1|1,L,R,x);
    push_up(rt);
}
int max_path(int u, int v) {
    int ans=0;
    while (top[u]!=top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        ans=max(ans,queryMax(1,n,1,dfn[top[u]],dfn[u]));
        u=par[top[u]];
    }
    if(u==v) return ans;
    if (dep[u]>dep[v]) swap(u,v);
    ans=max(ans,queryMax(1,n,1,dfn[son[u]],dfn[v]));
    return ans;
}   
void upd_path(int u,int v,int w) {
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        update(1,n,1,dfn[top[u]],dfn[u],w);
        u=par[top[u]];
    }
    if(u==v) return;
    if(dep[u]>dep[v]) swap(u,v);
    update(1,n,1,dfn[son[u]],dfn[v],w);
}
int ans[N];
int main() {
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        e[i].id=i, e[i].used = 0;
    }
    sort(e+1,e+1+m);
    for(int i=1;i<=n;i++) {
        fa[i]=-1;
    }
    for(int i=1;i<=m;i++) {
        int pu=find(e[i].u);
        int pv=find(e[i].v);
        if (pu != pv) {
            len[pv] = e[i].w;
            fa[pv] = pu;
            g[e[i].u].push_back(make_pair(e[i].v, e[i].w));
            g[e[i].v].push_back(make_pair(e[i].u, e[i].w));
            e[i].used = 1;
        }
    }

    int rt = find(1);
    pre(rt, rt); 
    dfs(rt, rt);

    build(1, n, 1);
    for (int i=1;i<=m;i++) {
        if (e[i].used == 0) {
            ans[e[i].id] = max_path(e[i].u, e[i].v) - 1;
        }
    }
    for (int i=1;i<4*N;i++)
        nod[i].Min = INF;

    for (int i=1;i<=m;i++) {
        if (e[i].used == 0) {
            upd_path(e[i].u, e[i].v, e[i].w);
        }
    }

    for (int i=1;i<=m;i++) {
        if (e[i].used == 1) {
            if (dfn[e[i].u] < dfn[e[i].v]) 
                swap(e[i].u, e[i].v);

            ans[e[i].id] = queryMin(1,n,1,dfn[e[i].u]) - 1;
        }
    }
    for (int i=1;i<=m;i++) {
        if (ans[i] > 1e9)
            ans[i] = -1;
        printf("%d ", ans[i]);
    }
}