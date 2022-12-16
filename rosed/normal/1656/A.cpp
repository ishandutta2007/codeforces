#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    int a[N];
    int maxn,p1,minn,p2;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            p1=p2=0;
            maxn=-inf,minn=inf;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(a[i]>maxn) maxn=a[i],p1=i;
                if(a[i]<minn) minn=a[i],p2=i;
            }
            cout<<p1<<' '<<p2<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
4 4
zzzz
z.z.
.zzz
zzzz

*/