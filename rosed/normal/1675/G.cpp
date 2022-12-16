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
    const int N=255,mod=1e9+7,inf=2e9;
    int n,m;
    int a[N],s[N];
    int dp[N][N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
        for(int k=m;k>=0;--k)
        {
            for(int j=k;j<=m;++j)
            {
                for(int i=1;i<=n;++i)
                {
                    dp[i][j]=min(dp[i][j],dp[i-1][j-k]+abs(s[i]-j));
                }
            }
        }
        cout<<dp[n][m]<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
6 4 7

6 6 5 5
3 7 8 5
*/