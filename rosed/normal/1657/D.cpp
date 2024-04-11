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
    int n,m,k;
    struct node
    {
        int w,v,h;
    }a[N];
    int f[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;T=1;
        while(T--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i].w>>a[i].v>>a[i].h;
                f[a[i].w]=max(f[a[i].w],a[i].v*a[i].h);
            }
            for(int i=1;i<=m;++i)
            {
                for(int j=2*i;j<=m;j+=i) f[j]=max(f[j],f[i]*(j/i));
            }
            for(int i=1;i<=m;++i) f[i]=max(f[i],f[i-1]);
            cin>>k;
            for(int i=1;i<=k;++i)
            {
                int v,h;
                cin>>v>>h;
                int t=upper_bound(f+1,f+m+1,v*h)-f;
                if(f[m]<=v*h) cout<<"-1 ";
                else cout<<t<<" ";
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
1
1 2 3 4

*/