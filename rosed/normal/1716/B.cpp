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
        int n;
        cin>>n;
        vector<int> a(n+1);
        cout<<n<<'\n';
        for(int i=1;i<=n;++i) a[i]=i;
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i) cout<<a[i]<<' ';
            cout<<'\n';
            if(k!=n) swap(a[k],a[k+1]);
        }
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
1 2 3 4 5
2 1 3 4 5
2 3 1 4 5
2 3 4 1 5


*/