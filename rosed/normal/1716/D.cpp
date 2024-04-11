#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=2e6+10,mod=998244353,inv2=5e8+4,inf=2e9;
    inline void main()
    {
        int n,k;
        cin>>n>>k;
        vector<int> f(n+1),g(n+1),ans(n+1);
        f[0]=1;
        for(int i=k,s=k;s<=n;++i,s+=i)
        {
            for(int j=0;j<=n;++j) g[j]=f[j];
            for(int j=i;j<=n;++j) f[j]=(f[j]+mod+f[j-i])%mod;
            for(int j=0;j<=n;++j) f[j]=(f[j]-g[j]+mod)%mod;
            for(int j=0;j<=n;++j) ans[j]=(ans[j]+f[j]+mod)%mod;
        }
        for(int i=1;i<=n;++i) cout<<ans[i]<<' ';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int qwq=1; //cin>>qwq;
    while(qwq--)
    red::main();
    return 0;
}
/*

*/