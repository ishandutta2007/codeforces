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
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x2-=x1;
        y2-=y1;
        int x,y;
        cin>>x>>y;
        int k1=abs(x2/x)&1,k2=abs(y2/y)&1;
        if(x2%x==0&&y2%y==0&&k1==k2) cout<<"YES\n";
        else cout<<"NO\n";
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

*/