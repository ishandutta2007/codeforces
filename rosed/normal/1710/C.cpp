#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=3e5+10,inf=2e9,mod=998244353,g=3,gi=332748118;
    int n,m;
    int dp[N][2][2][2][2][2][2];
    char s[N];
    inline int dfs(int now,int a,int b,int c,int x,int y,int z)
    {
        if(now==n)
        {
            return (x&y&z);
        }
        if(~dp[now][a][b][c][x][y][z]) return dp[now][a][b][c][x][y][z];
        int sum=0;
        for(int i=0;i<=1;++i)
        {
            if(a&&s[now]-'0'<i) continue;
            for(int j=0;j<=1;++j)
            {
                if(b&&s[now]-'0'<j) continue;
                for(int k=0;k<=1;++k)
                {
                    if(c&&s[now]-'0'<k) continue;
                    sum=(sum+dfs(now+1,a&(s[now]-'0'==i),b&(s[now]-'0'==j),c&(s[now]-'0'==k),x|((i^j)&(j^k)),y|((i^k)&(j^k)),z|((i^j)&(i^k))))%mod;
                }
            }
        }
        return dp[now][a][b][c][x][y][z]=sum;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>s;
        n=strlen(s);
        memset(dp,-1,sizeof(dp));
        cout<<dfs(0,1,1,1,0,0,0)<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*

*/