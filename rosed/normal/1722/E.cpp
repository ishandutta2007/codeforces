#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
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
        vector a(1001,vector<int>(1001));
        for(int i=1;i<=n;++i)
        {
            int x,y;
            cin>>x>>y;
            a[x][y]+=x*y;
        }
        for(int i=1;i<=1000;++i)
        {
            for(int j=1;j<=1000;++j)
            {
                a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
            }
        }
        for(int i=1;i<=m;++i)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            --x2,--y2;
            int sum=a[x2][y2]-a[x2][y1]-a[x1][y2]+a[x1][y1];
            cout<<sum<<'\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/