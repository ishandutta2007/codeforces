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
    const int N=5e5+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,m;
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>m;
            int sum=0,l=-inf,r=inf;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
            }
            l=a[1]-m,r=a[1]+m;
            for(int i=2;i<=n;++i)
            {
                l=max(l,a[i]-m),r=min(r,a[i]+m);
                if(l<=r) continue;
                l=a[i]-m,r=a[i]+m;
                ++sum;
            }
            cout<<sum<<'\n';
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