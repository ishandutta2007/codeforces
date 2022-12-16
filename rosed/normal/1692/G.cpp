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
    int n,k;
    int a[N],b[N],s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n>>k;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(i>1&&a[i]*2>a[i-1]) b[i]=1;
                else b[i]=0;
                s[i]=s[i-1]+b[i];
            }
            int ans=0;
            for(int i=k+1;i<=n;++i)
            {
                ans+=(s[i]-s[i-k]==k);
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
1 2 3
a
aa

*/