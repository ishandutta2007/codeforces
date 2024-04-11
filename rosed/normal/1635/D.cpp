#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=1e9+7,inf=2e9;
    int n,m,ans;
    int a[N];
    int f[N],g[N];
    map<int,int> q;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T=1;
        f[0]=f[1]=1;
        g[0]=1;
        for(int i=2;i<=2e5;++i) f[i]=(f[i-1]+f[i-2])%mod;
        for(int i=1;i<=2e5;++i) g[i]=(g[i-1]+f[i])%mod;
        while(T--)
        {
            cin>>n>>m;ans=0;
            q.clear();
            for(int i=1;i<=n;++i) cin>>a[i];
            sort(a+1,a+n+1);
            for(int i=1;i<=n;++i)
            {
                int x=a[i];
                int sum=0;
                while(x) ++sum,x>>=1;
                x=a[i];
                bool flag=0;
                while(x)
                {
                    if(q[x]){flag=1;break;}
                    if(x%4==0) x>>=2;
                    else if(x%2!=0) x>>=1;
                    else break;
                }
                q[a[i]]=1;
                if(flag) continue;
                if(sum<=m) ans=(ans+g[m-sum])%mod;
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

*/