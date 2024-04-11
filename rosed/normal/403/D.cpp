#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e5+10,inf=2e9,mod=1e9+7;
    int n;
    int f[1010][1010];
    int dp[1010][1010];
    int fac[N],inv[N];
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
    inline int C(int n,int m)
    {
        if(n<m) return 0;
        return fac[n]*inv[m]%mod*inv[n-m]%mod;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        f[0][0]=1;
        for(int i=1;i<=50;++i)
        {
            for(int j=i*(i+1)/2;j<=1000;++j)
            {
                f[i][j]=(f[i][j-i]+f[i-1][j-i])%mod;
            }
        }
        fac[0]=inv[0]=1;
        for(int i=1;i<=1000;++i) fac[i]=fac[i-1]*i%mod;
        inv[1000]=fast(fac[1000],mod-2);
        for(int i=999;i;--i) inv[i]=inv[i+1]*(i+1)%mod;
        for(int i=1;i<=50;++i)
        {
            for(int j=i*(i+1)/2;j<=1000;++j)
            {
                for(int k=i*(i+1)/2;k<=j;++k)
                {
                    dp[i][j]=(dp[i][j]+C(j-k+i,i)*f[i][k])%mod;
                }
                dp[i][j]=dp[i][j]*fac[i]%mod;
            }
        }
        int T;cin>>T;
        while(T--)
        {
            int x,y;cin>>x>>y;
            cout<<dp[y][x]<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
ans[k][n]=k! \sum_{i=1}^{n} C(n-i+k,k)f[k][i]
*/