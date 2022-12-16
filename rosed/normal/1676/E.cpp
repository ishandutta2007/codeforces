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
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n,m;
    int a[N],s[N];
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
                cin>>a[i];
            }
            sort(a+1,a+n+1);
            reverse(a+1,a+n+1);
            for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
            s[n+1]=inf;
            ++n;
            for(int i=1;i<=m;++i)
            {
                int x,t;cin>>x;
                t=lower_bound(s+1,s+n+1,x)-s;
                if(t==n) cout<<"-1\n";
                else cout<<t<<'\n';
            }
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