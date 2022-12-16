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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int g=__gcd(a,b);
        a/=g,b/=g;
        g=__gcd(c,d);
        c/=g,d/=g;
        if(a==c&&d==b) cout<<0<<'\n';
        else if(a==0||c==0||(a*d)%(b*c)==0||(b*c)%(a*d)==0) cout<<1<<'\n';
        else cout<<2<<'\n';
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