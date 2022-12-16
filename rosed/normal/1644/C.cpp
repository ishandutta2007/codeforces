#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5010,mod=201314,inf=2e9;
    int n,x;
    int a[N];
    int f[N][N];
    int ans[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>x;ans[0]=0;
            for(int i=1;i<=n;++i)
            {
                ans[i]=0;
                cin>>a[i];
            }
            for(int i=0;i<=n;++i)
                for(int j=0;j<=n;++j) f[i][j]=0;
            f[0][0]=0;
            for(int i=1;i<=n;++i)
            {
                for(int j=0;j<=i;++j)
                {
                    f[i][j]=max(f[i-1][j],0)+a[i];
                    if(j>0) f[i][j]=max(f[i-1][j-1],0)+a[i]+x;
                }
            }
            for(int i=0;i<=n;++i)
            {
                for(int j=0;j<=i;++j) ans[j]=max(ans[j],f[i][j]);
            }
            for(int i=0;i<=n;++i) ans[i]=max(ans[i],ans[i-1]);
            for(int i=0;i<=n;++i) cout<<ans[i]<<" \n"[i==n];
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}