#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 420000

const LL mod=998244353;
LL n,fa[N],f[N],sz[N],fac[N],ifac[N];

LL gfa(LL x){
    return fa[x]==x?x:fa[x]=gfa(fa[x]);
}

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

void init(LL n){
    fac[0]=1; for (LL i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
    ifac[n]=inv(fac[n]); for (LL i=n-1;~i;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
}

LL C(LL x,LL y){return fac[x]*ifac[y]%mod*ifac[x-y]%mod;}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (LL i=1;i<=n;++i){
        fa[i]=i;
        f[i]=1;
        sz[i]=1;
    }
    init(n*2);
    for (LL i=1;i<n;++i){
        LL x,y; cin>>x>>y;
        x=gfa(x); y=gfa(y);
        if (x>y) swap(x,y);
        fa[y]=x;
        LL sum=sz[x]+sz[y]-1;
        f[x]=f[x]*f[y]%mod*sz[x]%mod*sz[y]%mod*sz[x]%mod*sz[y]%mod;
        sz[x]+=sz[y];
    }
    LL ans=f[1];
    for (LL i=1;i<n;++i) ans=ans*(i*2-1)%mod;
    cout<<ans<<'\n';

    return 0;
}