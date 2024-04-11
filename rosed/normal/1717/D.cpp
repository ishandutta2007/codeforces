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
    const int N=1e6+10,mod=1e9+7,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        auto fast=[&](int x,int k) -> int
        {
            int ret=1;
            while(k)
            {
                if(k&1) ret=ret*x%mod;
                x=x*x%mod;
                k>>=1;
            }
            return ret;
        };
        int n,m;
        cin>>n>>m;
        m=min(n,m);
        int ans=0,x=1;
        for(int i=0;i<=m;++i)
        {
            ans=(ans+x)%mod;
            if(i!=n) x=x*(n-i)%mod*fast((i+1),mod-2)%mod;
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
1 7 5 6 8 2 6 5

0 8 5 6 8 0 8 5
3
5 6 5
3 8 5
2
3
8
*/