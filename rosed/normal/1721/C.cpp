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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        vector<int> a(n),b(n),c(n),d(n);
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        multiset<int> q;
        for(int i=0;i<n;++i) q.insert(b[i]);
        for(int i=0;i<n;++i)
        {
            int t1=lower_bound(b.begin(),b.end(),a[i])-b.begin();
            c[i]=b[t1]-a[i];
            cout<<c[i]<<" \n"[i==n-1];
        }
        for(int i=n-1;i>=0;--i)
        {
            auto it=q.end();
            --it;
            d[i]=*it-a[i];
            it=q.lower_bound(a[i]);
            q.erase(it);
        }
        for(int i=0;i<n;++i)
        {
            cout<<d[i]<<" \n"[i==n-1];
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