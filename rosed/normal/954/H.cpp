#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=5e5+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n;
    int a[N],s[N];
    int ans[N];
    signed f[5010][10010];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        s[0]=1;
        for(int i=1;i<n;++i)
        {
            cin>>a[i];
            s[i]=1ll*s[i-1]*a[i]%mod;
        }
        for(int i=n;i>=1;--i)
        {
            f[i][0]=1;
            for(int j=1;j<=n-i;++j)
            {
                f[i][j]=1ll*f[i+1][j-1]*a[i]%mod;
                ans[j]=(ans[j]+1ll*f[i][j]*s[i-1]%mod)%mod;
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=2*n-2;j>=1;--j)
            {
                f[i][j]=f[i-1][j-1];
                if(i>1&&j>1&&j<=i+n-2) f[i][j]=(f[i][j]+1ll*f[i][j-2]*(a[i-1]-1)%mod)%mod;
                ans[j]=(ans[j]+1ll*f[i][j]*s[i-1]%mod)%mod;
            }
        }
        for(int i=1;i<=2*n-2;++i) cout<<1ll*ans[i]*inv2%mod<<' ';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
aab

*/