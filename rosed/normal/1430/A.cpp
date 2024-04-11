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
        int n;
        cin>>n;
        for(int i=0;3*i<=n;++i)
        {
            int s=n-3*i;    
            int x=s/5,y=s%5,z=0;
            if(y==1||y==3) continue;
            while(y) y-=2,--x,++z;
            if(x<0) continue;
            cout<<i<<' '<<x<<' '<<z<<'\n';
            return;
        }
        cout<<"-1\n";
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