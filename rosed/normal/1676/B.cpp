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
    int a[N];
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
            }
            sort(a+1,a+n+1);
            int sum=0;
            for(int i=2;i<=n;++i) sum+=a[i]-a[1];
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
6 4 7

6 6 5 5
3 7 8 5
*/