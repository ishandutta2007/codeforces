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
    const int N=2e6+10,mod=998244353,inv2=5e8+4,inf=2e9;
    int fast(int x,int k)
    {
        int ret=1;
        while(k)
        {
            if(k&1) ret=ret*x%mod;
            x=x*x%mod;
            k>>=1;
        }
        return ret;
    }
    inline void main()
    {
        int n;cin>>n;
        n=abs(n);
        if(n==1) cout<<2<<'\n';
        else cout<<(n+2)/3<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int qwq=1; cin>>qwq;
    while(qwq--)
    red::main();
    return 0;
}
/*

*/