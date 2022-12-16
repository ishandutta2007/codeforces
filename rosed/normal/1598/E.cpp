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
    const int N=1e6+10,mod=998244353,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector dp(n+1,vector(m+1,vector<int>(2)));
        vector vis(n+1,vector<bool>(m+1));
        int tot=n*m,sum=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                dp[i][j][0]=dp[i-1][j][1]+1;
                dp[i][j][1]=dp[i][j-1][0]+1;
                sum+=dp[i][j][0]+dp[i][j][1];
                //cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<"!!!!!"<<endl;
            }
        }
        for(int i=1;i<=k;++i)
        {
            int x,y;
            cin>>x>>y;
            if(!vis[x][y])
            {
                vis[x][y]=1;
                for(int i=x;i<=n;++i)
                {
                    for(int j=max(1ll,y+(i-x-1));j<=min(m,y+(i-x+1));++j)
                    {
                        sum-=dp[i][j][0]+dp[i][j][1];
                        dp[i][j][0]=dp[i][j][1]=0;
                        if(vis[i][j]) continue;
                        dp[i][j][0]=dp[i-1][j][1]+1;
                        dp[i][j][1]=dp[i][j-1][0]+1;
                        sum+=dp[i][j][0]+dp[i][j][1];
                    }
                }
                --tot;
                
            }
            else
            {
                vis[x][y]=0;
                for(int i=x;i<=n;++i)
                {
                    for(int j=max(1ll,y+(i-x-1));j<=min(m,y+(i-x+1));++j)
                    {
                        sum-=dp[i][j][0]+dp[i][j][1];
                        dp[i][j][0]=dp[i][j][1]=0;
                        if(vis[i][j]) continue;
                        dp[i][j][0]=dp[i-1][j][1]+1;
                        dp[i][j][1]=dp[i][j-1][0]+1;
                        sum+=dp[i][j][0]+dp[i][j][1];
                        //cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<"!!!"<<endl;
                    }
                }
                
                ++tot;
            }
            cout<<sum-tot<<'\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
1 7 5 6 8 2 6 5

0 8 5 6 8 0 8 5
3
5 6 5
3 8 5
2
3
8
*/