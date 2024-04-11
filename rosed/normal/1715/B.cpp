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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,k,b,s;
        cin>>n>>k>>b>>s;
        vector<int> a(n+1);
        if(k*b>s)
        {
            cout<<"-1\n";
            return;
        }
        a[1]=k*b;
        s-=k*b;
        for(int i=1;i<=n;++i)
        {
            int tmp=min(k-1,s);
            a[i]+=tmp;
            s-=tmp;
        }
        if(s>0)
        {
            cout<<"-1\n";
            return;
        }
        for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
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