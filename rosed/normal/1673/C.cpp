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
    const int N=40000+10,mod=1e9+7,inf=2e9;
    int n,m;
    int f[N];
    int st[N],top;
    int g[N],num;
    int dp[N][501];
    inline bool check(int x)
    {
        int y=x;
        top=0;
        while(x) st[++top]=x%10,x/=10;
        int z=0;
        for(int i=1;i<=top;++i) z=z*10+st[i];
        return (z==y);
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        for(int j=0;j<=500;++j) dp[0][j]=1;
        for(int i=1;i<=40000;++i)
        {
            if(check(i))
            {
                g[++num]=i;
            }
            for(int j=1;j<=num;++j)
            {
              // cout<<i<<' '<<g[j]<<"!!"<<endl;
                dp[i][j]=dp[i-g[j]][j];
                //cout<<dp[i][j]<<"!!"<<endl;
            }
            for(int j=num;j>=1;--j) dp[i][j]=(dp[i][j]+dp[i][j+1])%mod;
        }
        while(T--)
        {
            cin>>n;
            cout<<dp[n][1]<<'\n';
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