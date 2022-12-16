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
    const int N=2000+10,mod=998244353,inf=2e9;
    int n,tot,ans;
    char s[N][N];
    int d[N*2][N*2];
    inline int work(int x,int y)
    {
        int tmp=min(n-x,n-y);
        int sum=d[x+tmp][y+tmp]-d[x-1][y-1];
        int tx=x+tmp+1,ty=y+tmp+1;
        if(tx>n) tx=1;
        if(ty>n) ty=1;
        tmp=n-tmp-2;
        sum+=d[tx+tmp][ty+tmp]-d[tx-1][ty-1];
        return (n-sum)+(tot-sum);
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {   
            cin>>n;tot=0;ans=n*n;
            for(int i=0;i<=n+1;++i)
                for(int j=0;j<=n+1;++j) d[i][j]=0;
            for(int i=1;i<=n;++i)
            {
                cin>>(s[i]+1);
                for(int j=1;j<=n;++j)
                {
                    tot+=(s[i][j]=='1');
                    d[i][j]=d[i-1][j-1]+(s[i][j]=='1');
                }
            }
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    ans=min(ans,work(i,j));
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
3
100
101
000

*/