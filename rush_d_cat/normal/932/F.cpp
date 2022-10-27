#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 6000000+10;
const int M = 100000+10;
struct Point {
    LL x,y;
};
LL dot(Point A, Point B) {
    return A.x*B.x + A.y*B.y;
}
LL f(Point A, int x) {
    return x*A.x + A.y;
}
vector<int> g[M];
Point line[N]; 
int n;LL a[M],b[M];
int lson[N],rson[N],tot,root[M]; LL dp[M];
void add(Point nw, int&rt,int l,int r) {
    if(!rt) rt=++tot;
    int m = (l+r)>>1;
    bool lef = f(nw, l) < f(line[rt], l);
    bool mid = f(nw, m) < f(line[rt], m);
    if(mid) swap(line[rt], nw);
    if(r-l==1) return;
    if(lef!=mid) add(nw,lson[rt],l,m);
    else add(nw,rson[rt],m,r);
}
LL get(int x,int rt,int l,int r){
    if(rt==0) return 1e12;
    int m = (l+r)>>1;
    if(r-l==1) return f(line[rt],x);
    if(x<m) return min(f(line[rt],x), get(x,lson[rt],l,m));
    return min(f(line[rt],x), get(x,rson[rt],m,r));
}
int merge(int x,int y,int l,int r) {
    if(x==0 || y==0) return x+y;
    add(line[y],x,l,r);
    int mid=(l+r)>>1;
    lson[x] = merge(lson[x],lson[y],l,mid);
    rson[x] = merge(rson[x],rson[y],mid,r);
    return x;
} 
void dfs(int u,int p) {
    for(auto v: g[u]) {
        if(v==p)continue;
        dfs(v,u);
        root[u]=merge(root[u],root[v],0,M<<1);
    }
    if(g[u].size()==1 && u!=1) dp[u]=0;
    else dp[u]=get(a[u]+M,root[u],0,M<<1);
    //printf("u=%d, dp=%lld\n", u,dp[u]);
    add((Point){b[u],dp[u]-b[u]*M},root[u],0,M<<1);
}
int main(){
    for(int i=0;i<N;i++) line[i].x=1e12,line[i].y=1e12;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++) printf("%lld ", dp[i]);
    printf("\n");
}
/*
dp[u] = dp[v] + a[u]*b[v]
*/