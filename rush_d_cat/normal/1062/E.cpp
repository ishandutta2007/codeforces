#include <iostream>
#include <vector>
using namespace std;
const int N = 100000+10;
int n,q,p[N][20],dep[N], dfn[N],out[N],C=0,who[N];
vector<int> g[N];
void init(){
    for(int j=1;j<20;j++)
    for(int i=1;i<=n;i++){
        p[i][j] = p[p[i][j-1]][j-1];
    }
}
void dfs(int u,int p){
    dfn[u]=++C; who[C]=u;
    for(auto v:g[u]){
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
    out[u]=C;
}
int lca(int u,int v){
    if(u==0)return v;
    if(v==0)return u;
    if(dep[u]<dep[v])swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=19;i>=0;i--){
        if(d>>i&1)u=p[u][i];
    }
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(p[u][i]!=p[v][i]){
            u=p[u][i],v=p[v][i];
        }
    }
    return p[u][0];
}
int go(int u,int d) {
    for(int i=19;i>=0;i--) {
        if(d>>i&1) u=p[u][i];
    } return u;
}
struct Nod {
    int top1,top2,bst;
    void prt() {
        printf("top1=%d, top2=%d, bst=%d\n", top1,top2,bst);
    }
    // 
    Nod operator + (const Nod & o) const {
        Nod res;
        res.top1 = lca(top1,o.top1);
        int bu1 = lca(top1,o.top2);
        int bu2 = lca(top2,o.top1);
        if (dep[bu1] < dep[bu2]) {
            res.top2 = bu1; res.bst = o.bst;
        } else {
            res.top2 = bu2; res.bst = bst;
        }
        return res;
    }
} nod[N<<2];
void pushup(int rt) {
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
void build(int l,int r,int rt){
    if(l==r) {
        nod[rt].top1 = l; nod[rt].top2 = 0; nod[rt].bst = l;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
Nod query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R){
        //printf("[%d,%d]\n", l,r); nod[rt].prt();
        return nod[rt];
    }
    int mid=(l+r)>>1;
    if(R<=mid) return query(l,mid,rt<<1,L,R);
    if(L >mid) return query(mid+1,r,rt<<1|1,L,R);
    return query(l,mid,rt<<1,L,R) + query(mid+1,r,rt<<1|1,L,R);
}


//
int lson[N*50],rson[N*50],tot,sum[N*50],root[N];
void update(int old_k,int &new_k,int l,int r,int pos) {
    new_k=++tot;
    lson[new_k]=lson[old_k],rson[new_k]=rson[old_k],sum[new_k]=sum[old_k]+1;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid) update(lson[old_k],lson[new_k],l,mid,pos);
    else update(rson[old_k],rson[new_k],mid+1,r,pos);
}
int query_k(int old_k,int new_k,int l,int r,int x) {
    if(l==r)return l;
    int mid=(l+r)>>1;
    int cnt=sum[lson[new_k]]-sum[lson[old_k]];
    if(x<=cnt) return query_k(lson[old_k],lson[new_k],l,mid,x);
    return query_k(rson[old_k],rson[new_k],mid+1,r,x-cnt);
}

int main(){
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++){
        scanf("%d",&p[i][0]);
        g[p[i][0]].push_back(i);
    }
    p[1][0]=1;
    dfs(1,1); init(); build(1,n,1);
    for(int i=1;i<=n;i++){
        update(root[i-1],root[i],1,n,dfn[i]);
    }
    //printf("## %d\n", go(10,10));
    while(q--) {
        int l,r; scanf("%d%d",&l,&r);
        // 
        if(l+1 == r) {
            if(dep[l] > dep[l+1]) {
                printf("%d %d\n", l+1,dep[l]);
            } else {
                printf("%d %d\n", l,dep[l+1]);
            }
            continue;
        }

        int v1 = query(1,n,1,l+1,r).top1, d1 = l;
        //printf("ok\n");
        int x1,y1,x2,y2;
        if (l+1==r) {
            x1=dfn[r],y1=dfn[r],x2=dfn[r],y2=dfn[r];
        } else {
            int bu = r-l;
            x1=query_k(root[l],root[r],1,n, 1); y1=query_k(root[l],root[r],1,n, bu-1);
            x2=query_k(root[l],root[r],1,n, 2); y2=query_k(root[l],root[r],1,n, bu);
        }
        //printf("%d %d %d %d\n", x1,y1,x2,y2);

        int lef = -1, rig = n;
        while(rig-lef>1){
            int mid=(lef+rig)>>1;
            int to = go(l, mid);
            //printf("l=%d, to=%d\n", l,to);
            //printf("[%d,%d]\n", dfn[to],out[to]);
            bool ok = 0;
            if(dfn[to] <= x1 && y1 <= out[to])
            {
                ok = 1;
                if(dep[to] > dep[v1]) {
                    v1 = to; d1 = who[y2];
                }
            } 
            if(dfn[to] <= x2 && y2 <= out[to])
            {
                ok = 1;
                if(dep[to] > dep[v1]) {
                    v1 = to; d1 = who[x1];
                }
            }
            if (ok) rig = mid; else lef = mid;
        } 
        //printf("v1 = %d\n", v1);
        printf("%d %d\n", d1,dep[v1]);
    }
}