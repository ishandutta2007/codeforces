#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,inf=1e9;
    int n,m;
    char s[N],t[N];
    int f[5010][5010],g[5010][5010];
    inline bool check()
    {
        int j=1;
        for(int i=1;i<=n&&j<=m;++i)
        {
            if(s[i]==t[j]) ++j;
        }
        return j>m;
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq; cin>>qwq;
        while(qwq--)
        {
            cin>>n>>m;
            cin>>(s+1)>>(t+1);
            if(!check())
            {
                cout<<"-1\n";
                continue;
            }
            for(int i=0;i<=n+1;++i)
                for(int j=0;j<=m+1;++j) f[i][j]=g[i][j]=inf;
            //cout<<f[0][1]<<"!!"<<endl;
            f[0][0]=0;
            for(int i=1;i<=n;++i)
            {
                for(int j=0;j<=m;++j)
                {
                    if(f[i-1][j]==0) f[i][j]=i+2;
                    else f[i][j]=f[i-1][j]+2;
                    if(s[i]==t[j])
                    { 
                        if(f[i-1][j-1]==0) f[i][j]=0;
                        else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
                    }
                }
            }
            g[n+1][m+1]=0;
            for(int i=n;i>=1;--i)
            {
                for(int j=m+1;j>=1;--j)
                {
                    if(g[i+1][j]<2*n) g[i][j]=n-i+1;
                    if(s[i]==t[j])
                    {
                        g[i][j]=min(g[i][j],g[i+1][j+1]);
                        //cout<<i<<' '<<j<<' '<<g[i][j]<<"!!"<<endl;
                    }
                }
            }
            //cout<<g[4][4]<<"!!"<<endl;
            int ans=inf;
            for(int i=0;i<=n;++i)
            {
                for(int j=0;j<=m;++j)
                {
                    //if(f[i][j]+g[i+1][j+1]==8) cout<<i<<' '<<j<<"!!"<<endl;
                    ans=min(ans,f[i][j]+g[i+1][j+1]);
                }
            }
            cout<<ans<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
6 4
aabcdd
abcd

*/