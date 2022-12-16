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
        vector<int> a(n+1);
        for(int i=1;i<=n;++i) a[i]=i;
        cout<<2<<'\n';
        for(int i=n;i>=2;--i)
        {
            cout<<a[i]<<' '<<a[i-1]<<'\n';
            a[i-1]=(a[i]+a[i-1]+1)/2;
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