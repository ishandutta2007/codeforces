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
    int n;
    int p[N],q[N];
    bool vis[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                cin>>p[i];
                q[i]=0;vis[i]=0;
            }
            if(n==1)
            {
                cout<<"-1\n";
                continue;
            }
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(p[i]==j||vis[j]) continue;
                    vis[j]=1;
                    q[i]=j;break;
                }
                if(!q[i])
                {
                    q[i]=q[i-1];
                    q[i-1]=p[i];
                }
            }
            for(int i=1;i<=n;++i) cout<<q[i]<<" \n"[i==n];
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