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
    const int N=1e6+10,mod=998244353,inv2=499122177,inf=2e18;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n;cin>>n;
        int sum=0;
        vector<int> a(n+1),b(n+1);
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            sum+=a[i];
        }
        for(int i=1;i<=n;++i)
        {
            int k=__lg(a[i]);
            b[i]=(1<<k);
        }
        for(int i=1;i<=n;++i) cout<<b[i]<<" \n"[i==n];
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