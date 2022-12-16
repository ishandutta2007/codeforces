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
    int a[N],b[N];
    int c[N];
    int tr[N];
    inline void update(int x,int k)
    {
        for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=k;
    }
    inline int query(int x)
    {
        int sum=0;
        for(int i=x;i>=1;i-=lowbit(i)) sum+=tr[i];
        return sum;
    }
    inline void init()
    {
        for(int i=1;i<=n;++i)
        {
            a[i]=b[i]=c[i]=tr[i]=0;
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;cin>>skx;
        while(skx--)
        {
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                ++c[a[i]];
            }
            for(int i=1;i<=n;++i) c[i]+=c[i-1];
            for(int i=1;i<=n;++i)
            {
                b[i]=c[a[i]]--;
            }
            int ans=0;
            for(int i=n;i>=1;--i)
            {
                ans+=query(b[i]);
                update(b[i],1);
            }
            cout<<ans<<'\n';
            init();
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