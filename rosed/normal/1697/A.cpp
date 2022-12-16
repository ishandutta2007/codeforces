#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n>>m;
            int sum=0;
            for(int i=1;i<=n;++i)
            {
                int x;cin>>x;
                sum+=x;
            }
            int ans=sum-m;
            if(ans<0) ans=0;
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
1 2 3
a
aa

*/