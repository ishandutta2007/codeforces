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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n;
    int a[N],s[N];
    int nxt[N],c[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
            }
            int ans=0;
            for(int i=n;i>=1;--i)
            {
                if(c[a[i]]!=0)
                {
                    ans=i;
                    break;
                }
                c[a[i]]=1;
            }
            cout<<ans<<'\n';
            for(int i=1;i<=n;++i)
            {
                c[a[i]]=0;
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
7 2 4 12
7 -5 2 8
7 -5 8 2
*/