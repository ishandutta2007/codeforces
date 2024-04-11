#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
const int inf=1e18;
void solve()
{
    int n;
    cin>>n;
    vector a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;++i)
    {
        cin>>a[i][i];
    }
    vector ok(n+1,vector<int>(n));
    for(int j=1;j<=n;++j)
    {
        for(int i=j-1;i>=1;--i)
        {
            a[i][j]=(a[j][j]-(j-i)*(j-1)%n+n)%n;
        }
        for(int i=j+1;i<=n;++i)
        {
            a[i][j]=(a[j][j]+(i-j)*(j-1)%n+n)%n;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout<<a[i][j]<<" \n"[j==n];
        }
    }
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=1;j<=n;++j)
    //     {
    //         for(int x=i;x<=n;++x)
    //         {
    //             for(int y=j;y<=n;++y)
    //             {
    //                 if(x==i||y==j) continue;
    //                 if((a[i][j]+a[x][y])%n==(a[i][y]+a[x][j])%n)
    //                 {
    //                     cout<<i<<' '<<j<<' '<<x<<' '<<y<<'\n';
    //                 }
    //             }
    //         }  
    //     }
    // }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}