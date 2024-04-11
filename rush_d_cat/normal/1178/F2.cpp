
 #include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long LL;
 
const LL MOD = 998244353;
const int N = 1000000 + 10;
 
int n,m,a[N],nex[N];
pair<int,int> mn[N<<2];
vector<int> v[N];
int MX[N];
 
void build(int l,int r,int rt) {
    if(l==r) {
        mn[rt]=make_pair(a[l],l); return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}
int mx[N<<2],lz[N<<2];
void pushdown(int rt){
    if(lz[rt]){
        mx[rt<<1]=max(mx[rt<<1],lz[rt]);
        mx[rt<<1|1]=max(mx[rt<<1|1],lz[rt]);
        lz[rt<<1]=max(mx[rt<<1],lz[rt]);
        lz[rt<<1|1]=max(lz[rt<<1|1],lz[rt]);
        lz[rt]=0;
    }
}
void update(int l,int r,int rt,int L,int R,int x){
    if(L<=l&&r<=R){
        lz[rt]=max(lz[rt],x); mx[rt]=max(mx[rt],x); return;
    }
    int mid=(l+r)>>1; pushdown(rt);
    if(L<=mid)update(l,mid,rt<<1,L,R,x);
    if(R >mid)update(mid+1,r,rt<<1|1,L,R,x);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
int querymx(int l,int r,int rt,int pos){
    if(l==r)return mx[rt];
    int mid=(l+r)>>1; pushdown(rt);
    if(pos<=mid)return querymx(l,mid,rt<<1,pos);
    return querymx(mid+1,r,rt<<1|1,pos);
}
pair<int,int> query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R)return mn[rt];
    int mid=(l+r)>>1;pair<int,int> ans=make_pair(N,N);
    if(L<=mid)ans=min(ans,query(l,mid,rt<<1,L,R));
    if(R >mid)ans=min(ans,query(mid+1,r,rt<<1|1,L,R));
    return ans;
}
LL MP(int x,int y){
    return 1LL*m*x+y;
}
unordered_map< LL,LL > dp;
void solve(int l,int r){
    if(l>=r) {
        dp[MP(l,r)]=1; return;
    }
    if(dp.count(MP(l,r))) return;
    pair<int,int> nod = query(1,m,1,l,r);
    int s=nod.second,t=s;
    LL ret=1;
    while(1){
        if(nex[t]==0 || nex[t]>r) break;
        solve(t+1,nex[t]-1); ret=ret*dp[MP(t+1,nex[t]-1)]%MOD;
        t=nex[t];
    }
    // [l,s)
    LL sum1=0;
    for(int i=l;i<=s;i++){
        //[l,i-1] [i,s-1]
        if((i==l||i==s) || (MX[i-1]<=nod.first)){
            solve(l,i-1);
            solve(i,s-1);
            sum1=(sum1+dp[MP(l,i-1)]*dp[MP(i,s-1)])%MOD;
        }
    }
 
    // (t,r]
    LL sum2=0;
    for(int i=t;i<=r;i++){
        //[t+1,i] [i+1,r]
        if(i==t||i==r|| (MX[i]<=nod.first)){
            solve(t+1,i);
            solve(i+1,r);
            sum2=(sum2+dp[MP(t+1,i)]*dp[MP(i+1,r)])%MOD;
        }
    }
    ret=ret*sum1%MOD*sum2%MOD;
    //printf("[%d, %d] : %lld\n", l,r,ret);
    dp[MP(l,r)] = ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    int mm = 0;
    for(int i=1;i<=m;i++) if(a[i]!=a[i-1]) a[++mm]=a[i];
    m=mm;
    for(int i=1;i<=m;i++){
        v[a[i]].push_back(i);
    }
    build(1,m,1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<(int)v[i].size()-1;j++){
            nex[v[i][j]] = v[i][j+1];
            update(1,m,1,v[i][j],v[i][j+1]-1,i);
            if(v[i][j]+1<=v[i][j+1]-1 && query(1,m,1,v[i][j]+1,v[i][j+1]-1).first < i) {
                return !printf("0\n");
            }
        }
    }
    for(int i=1;i<=m;i++) MX[i]=querymx(1,m,1,i);
    solve(1,m);
    cout<<dp[MP(1,m)]<<endl;
}