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
    int a[N],ans;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            int tsum=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                tsum+=a[i];
            }
            //b[i]=a[i]+t
            //b[u]*b[v]-t^2
            sort(a+1,a+n+1);
            if(a[n]*(n-2)+tsum<0||a[1]*(n-2)+tsum>0)
            {
                cout<<"INF\n";
                continue;
            }
            int dv=0;
            int val=0;
            for(int i=2;i<=n;++i)
            {
                val+=a[1]+a[i];
                dv+=a[1]*a[i];
            }
            ans=-inf*inf;
            for(int i=2;i<=n;++i)
            {
                int l=-a[i],r=-a[i-1];
                ans=max(ans,max(val*l+dv,val*r+dv));
                val-=a[1];
                val+=a[n];
                dv+=a[i]*(a[n]-a[1]);
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
4 4
zzzz
z.z.
.zzz
zzzz

*/