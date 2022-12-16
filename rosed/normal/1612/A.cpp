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
        int x,y,d=0;
        cin>>x>>y;
        d=x+y;
        if(d&1)
        {
            cout<<"-1 -1\n";
            return;
        }
        int b1=x&1,b2=y&1;
        if(!b1&&!b2) cout<<x/2<<' '<<y/2<<'\n';
        else
        {
            if(x>y) cout<<x-d/2<<' '<<y<<'\n';
            else cout<<x<<' '<<y-d/2<<'\n';
        }
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