#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fxaa
#define y0 fxbb
#define x1 fxcc
#define y1 fxdd
#define st first
#define nd second
#define eb emplace_back
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=2e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
int n,m,a,b;
int pw(int x,int y){
    int s=1;
    for(;y;y>>=1,x=1ll*x*x%mod)
        if(y&1)s=1ll*s*x%mod;
    return s;
}
int fra[N];
inline int C(int n,int m){return 1ll*fra[n]*pw(fra[m],mod-2)%mod*pw(fra[n-m],mod-2)%mod;}
inline int P(int n,int m){return 1ll*fra[n]*pw(fra[n-m],mod-2)%mod;}
inline int F(int n,int m){
    if(m==n)return 1;
    return 1ll*m*pw(n,n-m-1)%mod;
}
int main(){
    fra[0]=1;
    rep(i,N-1)fra[i]=1ll*fra[i-1]*i%mod;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    int ans=0;
    rep(i,min(n-1,m)){
        //printf("%d %d %d %d\n",P(n-2,i-1),F(n,i+1),C(m-1,i-1),pw(m,n-1-i));
        ans=(ans+1ll*C(m-1,i-1)*P(n-2,i-1)%mod*F(n,i+1)%mod*pw(m,n-1-i))%mod;
    }
    printf("%d\n",ans);
    return 0;
}