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
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        if(n<m)
        {
            cout<<"NO\n";
            return;
        }
        vector dp(n+1,vector(2*m+2,vector<int>(3,0)));
        vector g(n+1,vector(2*m+2,vector<int>(3,0)));
        if(s[0]=='?')
        {
            if(m!=1||n==1)dp[0][m+1][1]=1;
            if(m!=1||n==1)dp[0][m-1][2]=1;
            dp[0][m][0]=1;
        }
        if(s[0]=='W'&&(m!=1||n==1)) dp[0][m+1][1]=1;
        if(s[0]=='L'&&(m!=1||n==1)) dp[0][m-1][2]=1;
        if(s[0]=='D') dp[0][m][0]=1;
        for(int i=1;i<n-1;++i)
        {
            for(int j=1;j<2*m;++j)
            {
                for(int k=0;k<=2;++k)
                {
                    if(s[i]=='W'||s[i]=='?')
                    {
                        if(dp[i-1][j-1][k])
                        {
                            dp[i][j][1]=1;
                            g[i][j][1]=k;
                        }
                    }
                    if(s[i]=='L'||s[i]=='?')
                    {
                        if(dp[i-1][j+1][k])
                        {
                            dp[i][j][2]=1;
                            g[i][j][2]=k;
                        }
                    }
                    if(s[i]=='D'||s[i]=='?')
                    {
                        if(dp[i-1][j][k])
                        {
                            dp[i][j][0]=1;
                            g[i][j][0]=k;
                        }
                    }
                }
                
            }
        }
        for(int i=max(1ll,n-1);i<=n-1;++i)
        {
            for(int j=0;j<=2*m;++j)
            {
                for(int k=0;k<=2;++k)
                {
                    if(s[i]=='W'||s[i]=='?')
                    {
                        if(j>0&&dp[i-1][j-1][k])
                        {
                            dp[i][j][1]=1;
                            g[i][j][1]=k;
                        }
                    }
                    if(s[i]=='L'||s[i]=='?')
                    {
                        if(j<2*m&&dp[i-1][j+1][k])
                        {
                            dp[i][j][2]=1;
                            g[i][j][2]=k;
                        }
                    }
                    if(s[i]=='D'||s[i]=='?')
                    {
                        if(dp[i-1][j][k])
                        {
                            dp[i][j][0]=1;
                            g[i][j][0]=k;
                        }
                    }
                }
            }
        }
        int t1=-1,t2=-1;
        for(int k=0;k<=2;++k) if(dp[n-1][2*m][k]) t1=2*m,t2=k;
        for(int k=0;k<=2;++k) if(dp[n-1][0][k]) t1=0,t2=k;
        if(t1==-1)
        {
            cout<<"NO\n";
            return;
        }
        for(int i=n-1;i>=0;--i)
        {
            int tt=t1;
            if(t2==0) s[i]='D';
            if(t2==1) s[i]='W',--t1;
            if(t2==2) s[i]='L',++t1;
            t2=g[i][tt][t2];
        }
        cout<<s;
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

*/