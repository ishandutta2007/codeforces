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
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    int a[1510];
    int b[1510];
    struct node
    {
        int x,y,v;
        inline bool operator < (const node &t) const
        {
            return v<t.v;
        }
    }q[1500*1500+10];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                int x;cin>>x;
                q[++m]=(node){i,j,x};
            }
        }
        sort(q+1,q+m+1);
        int ans=0;
        for(int i=1;i<=m;++i)
        {
            ans+=a[q[i].x]*(n-1-b[q[i].y])+b[q[i].y]*(n-1-a[q[i].x]);
            ++a[q[i].x],++b[q[i].y];
        }
        cout<<ans/2<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
5
1 2
2 3
3 4
3 5

*/