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
const int N=15,mod=1e9+7;
int n,a[N],dp[1<<14],to[N][N],pre[N][1<<14];
int pw(int x,int y=mod-2){
    int s=1;
    x%=mod;
    for(;y;y>>=1,x=(ll)x*x%mod)
        if(y&1)s=(ll)s*x%mod;
    return s;
}
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i);
    rep(i,n)rep(j,n)to[i][j]=(ll)a[i]*pw(a[i]+a[j])%mod;
    rep(i,n)for(int mk=0;mk<1<<n;++mk){
        pre[i][mk]=1;
        rep(j,n)if((mk&(1<<(j-1)))>0)
            pre[i][mk]=(ll)pre[i][mk]*to[i][j]%mod;
    }
    int ans=0;
    for(int mk=1;mk<1<<n;++mk){
        dp[mk]=1;
        for(int mk2=(mk-1)&mk;mk2;mk2=(mk2-1)&mk){
            int d=dp[mk2],cnt=0;
            rep(i,n)if((mk2&(1<<(i-1)))>0)
                d=(ll)d*pre[i][mk^mk2]%mod,++cnt;
            if(mk==(1<<n)-1){
                ans=(ans+(ll)cnt*d)%mod;
            }
            dp[mk]=(dp[mk]-d+mod)%mod;
            //printf("%d %d %d\n",mk,mk2,d);
        }
        //printf("%d %d\n",mk,dp[mk]);
        if(mk==(1<<n)-1)
            ans=(ans+(ll)n*dp[mk])%mod;
    }
    printf("%d\n",ans);
    return 0;
}
/*
7 6
1 6 4 2 3 5 4

*/