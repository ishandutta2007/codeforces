#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=1e9+7;
    int n;
    int pw[N];
    int fac[N];
    int dp[1000010],tot[1000010];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        pw[0]=fac[0]=1;
        for(int i=1;i<=40;++i) pw[i]=pw[i-1]*2;
        for(int i=1;i<=15;++i) fac[i]=fac[i-1]*i;
        for(int s=0;s<(1<<15);++s)
        {
            int sum=0;
            for(int k=0;k<15;++k)if((s>>k)&1)
            {
                sum+=fac[k];
                ++tot[s];
            }
            dp[s]=sum;
        }
        while(T--)
        {
            cin>>n;
            int ans=1e18;
            for(int s=0;s<(1<<15);++s)if(dp[s]<=n)
            {
                int tmp=n-dp[s];
                if((tmp&1==1)||(tmp&2==1)) continue;
                int ret=tot[s];
                while(tmp)
                {
                    if(tmp&1) ++ret;
                    tmp>>=1;
                }
                ans=min(ans,ret);
            }
            if(ans>1e12) cout<<"-1\n";
            else cout<<ans<<'\n'; 
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*

*/