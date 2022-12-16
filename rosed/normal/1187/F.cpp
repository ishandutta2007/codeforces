#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=5e5+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,sum,ret;
    int l[N],r[N],len[N],inv[N];
    int ans[N];
    inline int fast(int x,int k)
    {
        int ret=1;
        while(k)
        {
            if(k&1) ret=ret*x%mod;
            x=x*x%mod;
            k>>=1;
        }
        return ret;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i) cin>>l[i];
        for(int i=1;i<=n;++i) cin>>r[i];
        inv[0]=1;
        for(int i=1;i<=n;++i)
        {
            len[i]=r[i]-l[i]+1;
            inv[i]=fast(len[i],mod-2);
            ans[i]=(1-max(0ll,min(r[i],r[i-1])-max(l[i],l[i-1])+1)*inv[i]%mod*inv[i-1]%mod+mod)%mod;
            if(i>2)
            {
                sum=(sum+ans[i-2])%mod;
            }
            ret=((ret+ans[i])%mod+2*sum*ans[i]%mod)%mod;
        }
        for(int i=1;i<n;++i)
        {
            int p=(1-(1-ans[i])-(1-ans[i+1]))%mod;
            int tmp=max(0ll,min(min(r[i-1],r[i+1]),r[i])-max(max(l[i-1],l[i+1]),l[i])+1)*inv[i-1]%mod*inv[i]%mod*inv[i+1]%mod;
            ret=(ret+2*(p+tmp))%mod;
        }
        cout<<(ret%mod+mod)%mod<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*

*/