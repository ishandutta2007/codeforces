#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=5e5+5,mod=1e9+7;
const ll inf=4e18;
int n,q;
ll a[3][N];
vector<pr>g[N];
ll dp[N],mad[19][N];
struct node{
    ll x,y,s;
    node operator+(node p){return (node){max(x,p.x),max(y,p.y),max(x+p.y,max(s,p.s))};}
}t[N<<2];
void init(int p,int l,int r){
    if(l==r){
        t[p]=(node){dp[l],a[1][l],dp[l]+a[1][l]};
        return;
    }
    int mid=(l+r)/2;
    init(p<<1,l,mid);init(p<<1|1,mid+1,r);
    t[p]=t[p<<1]+t[p<<1|1];
}
node que(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y)return t[p];
    node ret=(node){-inf,-inf,-inf};
    int mid=(l+r)/2;
    if(x<=mid)ret=ret+que(p<<1,l,mid,x,y);
    if(mid+1<=y)ret=ret+que(p<<1|1,mid+1,r,x,y);
    return ret;
}
int main(){
    scanf("%d%d",&n,&q);
    rep(i,n)scanf("%lld",a[0]+i);
    rep(i,n)a[0][i]+=a[0][i-1];
    rep(i,n)scanf("%lld",a[2]+i);
    rep(i,n)a[2][i]+=a[2][i-1];
    rep(i,n)a[0][i]-=a[2][i-1];
    rep(i,n)scanf("%lld",a[1]+i);
    for(int i=n;i;--i)a[1][i]+=a[1][i+1];
    rep(i,n)a[1][i]+=a[2][i];
    // rep(i,n)printf("%lld%c",a[0][i]," \n"[i==n]);
    // rep(i,n)printf("%lld%c",a[1][i]," \n"[i==n]);
    rep(i,q){
        int l,r,k;scanf("%d%d%d",&l,&r,&k);
        g[r].pb(mp(l,k));
    }
    rep(i,n){
        dp[i]=a[0][i];
        for(pr p:g[i-1]){
            int x=i-1;
            for(int j=18;~j;--j)if(x-(1<<j)>=p.st-1){
                dp[i]=max(dp[i],mad[j][x]-p.nd);
                x-=1<<j;
            }
        }
        mad[0][i]=dp[i];
        rep(j,18)mad[j][i]=max(mad[j-1][i],mad[j-1][max(1,i-(1<<(j-1)))]);
    }
    // rep(i,n)printf("%lld%c",dp[i]," \n"[i==n]);
    init(1,1,n);
    ll ans=-inf;
    rep(i,n)for(pr p:g[i]){
        ans=max(ans,que(1,1,n,p.st,i).s-p.nd);
        // printf("%d %d %d %lld\n",p.st,i,p.nd,que(1,1,n,p.st,i).s);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
*/