#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=300+10,mod=998244353,inf=2e9;
    int n,m;
    int dp[N][N];
    int g[N][N];
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
    inline int dc(int l,int r)
    {
        return (l+r)*(r-l+1)/2;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;--n;
        dp[0][0]=g[0][0]=1;
        fac[0]=inv[0]=1;
        for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
        inv[n]=fast(fac[n],mod-2);
        for(int i=n-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
        for(int i=0;i<=n;++i)
        {
            //g[i][0]=dp[i][0];
            for(int j=1;j<=m;++j) g[i][j]=(g[i][j-1]+dp[i][j])%mod;
            for(int j=1;j<=m;++j)
            {
                for(int k=1;k<=n-i;++k)
                {
                    int sum=dc(i,i+k-1);
                    //cout<<i+k<<' '<<j<<' '<<g[i][j-1]*fast(m-j+1,sum)<<"!!"<<endl;
                    dp[i+k][j]=(dp[i+k][j]+g[i][j-1]*fast(m-j+1,sum)%mod*inv[k]%mod)%mod;
                }
            }
        }
        cout<<g[n][m]*fac[n]%mod<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
1
1 2 3 4

*/