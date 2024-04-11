#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
typedef long double ld;
const ld eps=1e-9;
const int N=3605,mod=998244353;
int h,w,n;bool a[N],b[N];
int numa,numb,dpa[N],dpb[N],tmp[N];
int fra[N],rev[N];
int pw(int x,int y=mod-2){
    int s=1;
    for(;y;y>>=1,x=1ll*x*x%mod)
        if(y&1)s=1ll*s*x%mod;
    return s;
}
int C(int n,int m){
    if(n<m||m<0)return 0;
    return 1ll*fra[n]*rev[m]%mod*rev[n-m]%mod;
}
int main(){
    fra[0]=1;
    rep(i,N-1)fra[i]=1ll*fra[i-1]*i%mod;
    rev[N-1]=pw(fra[N-1]);
    for(int i=N-2;~i;--i)rev[i]=1ll*rev[i+1]*(i+1)%mod;
    scanf("%d%d%d",&h,&w,&n);
    rep(i,n){
        int X0,Y0,X1,Y1;scanf("%d%d%d%d",&X0,&Y0,&X1,&Y1);
        a[X0]=a[X1]=1;
        b[Y0]=b[Y1]=1;
    }
    dpa[0]=1;
    int la=0;
    a[h+1]=1;
    rep(i,h+1){
        if(!a[i])++la,++numa;
        else{
            memcpy(tmp,dpa,sizeof dpa);
            memset(dpa,0,sizeof dpa);
            for(int i=0;i<N;++i)if(tmp[i]>0)
                for(int j=0;j<=la/2;++j)
                    dpa[i+j]=(dpa[i+j]+1ll*tmp[i]*C(la-j,j))%mod;
            la=0;
        }
    }
    dpb[0]=1;
    la=0;
    b[w+1]=1;
    rep(i,w+1){
        if(!b[i])++la,++numb;
        else{
            memcpy(tmp,dpb,sizeof dpb);
            memset(dpb,0,sizeof dpb);
            for(int i=0;i<N;++i)if(tmp[i]>0)
                for(int j=0;j<=la/2;++j)
                    dpb[i+j]=(dpb[i+j]+1ll*tmp[i]*C(la-j,j))%mod;
            la=0;
        }
    }
    int ans=0;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            ans=(ans+1ll*dpa[i]*C(numa-i*2,j)%mod*dpb[j]%mod*C(numb-j*2,i)%mod*fra[i]%mod*fra[j])%mod;
    printf("%d\n",ans);
    return 0;
}