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
    const int N=3e5+10,mod=998244353,inv2=5e8+4,inf=2e9;
    vector S2(2001,vector<int>(2001));
    vector<int> fac(2001);
    void _init_(int n=2000)
    {
        S2[0][0]=1;
        for(int i=0;i<=n;++i)
        {
            for(int j=1;j<=i;++j)
            {
                S2[i][j]=(S2[i-1][j-1]+j*S2[i-1][j])%mod;
            }
        }
        fac[0]=1;
        for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
    }
    inline void main()
    {
        int n,m,k;cin>>n>>m>>k;
        int ans=0;
        auto fast=[&](int x,int k) -> int
        {
            int ret=1;
            while(k)
            {
                if(k&1) ret=ret*x%mod;
                x=x*x%mod;
                k>>=1;
            }
            return ret;
        };
        int x=(m+1)/2,y=m-x,cc=1;
        int lim=min(n,k);
        for(int i=0;i<=lim;++i)
        {
            ans=(ans+S2[k][i]*fac[i]%mod*cc%mod*fast(x+y,n-i)%mod*fast(x,i)%mod)%mod;
            //cout<<n<<' '<<i<<' '<<cc<<"!!!"<<endl;
            cc=cc*(n-i)%mod*fast(i+1,mod-2)%mod;
            
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::_init_();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/