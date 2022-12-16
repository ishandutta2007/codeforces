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
    const int N=2e6+10,mod=998244353,inv2=5e8+4,inf=2e9;
    int fast(int x,int k)
    {
        int ret=1;
        while(k)
        {
            if(k&1) ret=ret*x%mod;
            x=x*x%mod;
            k>>=1;
        }
        return ret;
    }
    inline void main()
    {
        int n,m,k;cin>>n>>m>>k;
        int sum1=n,sum2=m;
        vector a(n+1,vector<int>(2));
        vector b(m+1,vector<int>(2));
        vector<int> d(2);
        int c1=0,c2=0;
        vector<map<int,int>> mp(1000001);
        auto del=[&](int x,int y) -> void
        {
            if(!mp[x][y]) return;
            int c=mp[x][y]-1;mp[x][y]=0;
            if(a[x][(y&1)^c]==1&&a[x][(y&1)^c^1]>0) --c1;
            if(b[y][(x&1)^c]==1&&b[y][(x&1)^c^1]>0) --c2;
            if(a[x][(y&1)^c]==1) ++sum1;
            if(b[y][(x&1)^c]==1) ++sum2;
            --a[x][(y&1)^c];
            --b[y][(x&1)^c];
            --d[((x+y)&1)^c];
        };
        auto add=[&](int x,int y,int c) -> void
        {
            mp[x][y]=c+1;
            if(a[x][(y&1)^c]==0&&a[x][(y&1)^c^1]>0) ++c1;
            if(b[y][(x&1)^c]==0&&b[y][(x&1)^c^1]>0) ++c2;
            if(a[x][(y&1)^c]==0) --sum1;
            if(b[y][(x&1)^c]==0) --sum2;
            ++a[x][(y&1)^c];
            ++b[y][(x&1)^c];
            ++d[((x+y)&1)^c];
        };
        auto query=[&](int x,int y) -> int
        {
            int sum=0;
            if(!c1) sum=(sum+fast(2,sum1));
            if(!c2) sum=(sum+fast(2,sum2));
            if(!d[0]) --sum;
            if(!d[1]) --sum;
            return (sum%mod+mod)%mod;
        };
        for(int i=1;i<=k;++i)
        {
            int x,y,z;cin>>x>>y>>z;
            del(x,y);
            if(z!=-1) add(x,y,z);
            cout<<query(x,y)<<'\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::main();
    return 0;
}
/*

*/