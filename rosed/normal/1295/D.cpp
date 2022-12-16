#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int a,n;
        cin>>a>>n;
        int g=__gcd(a,n);
        n/=g;
        int ans=n;
        for(int x=2;x*x<=n;++x)
        {
            if(n%x==0)
            {
                ans=ans/x*(x-1);
                while(n%x==0) n/=x;
            }
        }
        if(n!=1) ans=ans/n*(n-1);
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/