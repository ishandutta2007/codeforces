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
    const int N=4e5+10,mod=998244353,inf=2e9;
    int n,a,b,ans;
    int p[N],s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>a>>b;ans=inf*inf;
            for(int i=1;i<=n;++i)
            {
                cin>>p[i];
            }
            s[n+1]=0;
            for(int i=n;i>=1;--i) s[i]=s[i+1]+p[i];
            for(int i=0;i<=n;++i)
            {
                ans=min(ans,(a+b)*p[i]+(s[i+1]-p[i]*(n-i))*b);
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
1 2 3 4

*/