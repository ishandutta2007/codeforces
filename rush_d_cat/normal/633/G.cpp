#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
const int M=1000;
int n,q,m;
int prime[M],vis[M];
void init(){
    for(int i=2;i<M;i++){
        if(vis[i]==0) {
            prime[++prime[0]]=i;
        }
        for(int j=2*i;j<M;j+=i) vis[j]=1;
    }
}
const int N=100000+10;
typedef bitset<2000> B;
vector<int> g[N];
void prt(B st) {
    printf("bitset=\n");
    for(int i=0;i<m;i++){
        if(st[i]) printf("%d ", i);
    } printf("\n");
}
B nod[N<<2], all[1002]; int lz[N<<2],a[N],dfn[N],rdfn[N],who[N],CLOCK;
void shift(B &b,int x) {
    //prt(b);
    if(x<=0)return;
    b<<=x; b|=((b>>m)&all[x]);
    //prt(b);
}
void dfs(int u,int p){
    dfn[u]=++CLOCK, who[CLOCK]=u;
    for(auto v:g[u]){
        if(v==p)continue; dfs(v,u);
    }
    rdfn[u]=CLOCK;
}
void pushup(int rt){
    nod[rt]=nod[rt<<1]|nod[rt<<1|1];
}
void pushdown(int rt){
    if(lz[rt]){
        shift(nod[rt<<1],lz[rt]);
        shift(nod[rt<<1|1],lz[rt]); 
        (lz[rt<<1]+=lz[rt])%=m; 
        (lz[rt<<1|1]+=lz[rt])%= m;
        lz[rt] = 0;
    }
}
void build(int l,int r,int rt){
    if(l==r){
        a[who[l]]%=m; nod[rt].reset(); nod[rt].set(a[who[l]]); return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1); build(mid+1,r,rt<<1|1);
    pushup(rt);
}
void update(int l,int r,int rt,int L,int R,int x) {
    if(L<=l&&r<=R) {
        x%=m; shift(nod[rt],x); (lz[rt]+=x)%=m; return;
    }
    pushdown(rt); int mid=(l+r)>>1;
    if(L<=mid)update(l,mid,rt<<1,L,R,x);
    if(R >mid)update(mid+1,r,rt<<1|1,L,R,x);
    pushup(rt);
}
B query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) return nod[rt];
    pushdown(rt); int mid=(l+r)>>1;
    if(R<=mid)return query(l,mid,rt<<1,L,R);
    if(L >mid)return query(mid+1,r,rt<<1|1,L,R);
    return query(l,mid,rt<<1,L,R) | query(mid+1,r,rt<<1|1,L,R);
}
int count(B st) {
    int ans=0;
    for(int i=1;i<=prime[0];i++) {
        if(prime[i]>=m)break;
        if(st[prime[i]]) ans++;
    }
    return ans;
}
int main() {
    init();
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    for(int j=0;j<i;j++) all[i].set(j);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v); 
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1,1);
    build(1,n,1);
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int op,v,x;
        scanf("%d%d",&op,&v);
        if(op==2) {
            printf("%d\n", count(query(1,n,1,dfn[v],rdfn[v])));
        } else {
            scanf("%d",&x); update(1,n,1,dfn[v],rdfn[v],x);
        }
    }
}
/*
6 6
0 0 0 0 0 0 
1 2
2 3
2 4
1 5
5 6
100
1 2 2
1 3 1
1 4 3
2 1


6 6
2 2 2 2 2 2
1 2
2 3
2 4
1 5
5 6
100
2 1
*/