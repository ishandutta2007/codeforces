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
#define y1 pizza
    const int N=1e6+10,mod=998244353,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        int x0=0,y0=0,x1=0,y1=0;
        for(int i=1;i<=n;++i)
        {
            int x,y;
            cin>>x>>y;
            if(x<0) x0=min(x0,x);
            if(x>0) x1=max(x1,x);
            if(y<0) y0=min(y0,y);
            if(y>0) y1=max(y1,y);
        }
        cout<<2*(x1+y1-x0-y0)<<'\n';
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