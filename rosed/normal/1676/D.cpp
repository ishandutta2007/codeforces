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
    const int N=500+10,mod=1e9+7,inf=2e9;
    int n,m;
    int a[N][N];
    int dx[4]={-1,1,1,-1},dy[4]={1,1,-1,-1};
    int ans;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;cin>>skx;
        while(skx--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    cin>>a[i][j];
                }
            }
            ans=0;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    int sum=a[i][j];
                    for(int k=0;k<4;++k)
                    {
                        int x=i+dx[k],y=j+dy[k];
                        while(x>=1&&x<=n&&y>=1&&y<=m)
                        {
                            sum+=a[x][y];
                            x+=dx[k],y+=dy[k];
                        }
                        ans=max(ans,sum);
                    }
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
6 4 7

6 6 5 5
3 7 8 5
*/