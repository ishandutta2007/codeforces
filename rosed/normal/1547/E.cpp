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
        int n,m;
        cin>>n>>m;
        vector<int> a(n,inf);
        vector<int> b(n,-1);
        vector<int> p(m);
        for(int i=0;i<m;++i) cin>>p[i];
        for(int i=0;i<m;++i) cin>>b[p[i]-1];
        int minn=inf;
        for(int i=0;i<n;++i)
        {
            if(b[i]!=-1) minn=min(minn,b[i]-i);
            a[i]=min(a[i],minn+i);
        }
        minn=inf;
        for(int i=n-1;i>=0;--i)
        {
            if(b[i]!=-1) minn=min(minn,b[i]+i);
            a[i]=min(a[i],minn-i);
        }
        for(int i=0;i<n;++i) cout<<a[i]<<" \n"[i==n-1];
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