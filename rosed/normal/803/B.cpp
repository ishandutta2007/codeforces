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
        int n;
        cin>>n;
        vector<int> a(n+2);
        vector<int> b(n+2,inf),c(n+2,inf);
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            b[i]=b[i-1]+1;
            if(!a[i]) b[i]=0;
        }
        for(int i=n;i>=1;--i)
        {
            c[i]=c[i+1]+1;
            if(!a[i]) c[i]=0;
        }
        for(int i=1;i<=n;++i) cout<<min(b[i],c[i])<<' ';
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