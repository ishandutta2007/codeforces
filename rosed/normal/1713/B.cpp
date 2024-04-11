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
    const int N=1e6+10,mod=998244353,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;cin>>n;
        int maxn=0;
        vector<int> a(n+1);
        int sum=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            sum+=max(0ll,a[i]-a[i-1]);
            maxn=max(maxn,a[i]);
        }
        if(sum==maxn) cout<<"YES\n";
        else cout<<"NO\n";

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