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
    int a[N];
    int s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                s[i]=s[i-1]+a[i];
            }
            if(m>s[n])
            {
                cout<<-1<<'\n';
                continue;
            }
            int posr=0;
            for(int i=1;i<=n;++i)
            {
                if(s[i]==m) posr=i+1;
            }
            int ans=n-posr+1;
            for(int l=1;l<=n;++l)
            {
                if(s[n]-s[l]<m) break;
                while(s[posr]-s[l]<=m&&posr<=n) ++posr;
                ans=min(ans,l+n-posr+1);
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
3 1
1 1 0

*/