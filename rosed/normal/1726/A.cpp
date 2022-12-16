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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        vector<int> a(n+1);
        int minn=inf,maxn=-inf;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            minn=min(a[i],minn);
            maxn=max(a[i],maxn);
        }
        a[n]=a[0];
        ans=max(a[n-1]-minn,maxn-a[0]);
        for(int i=0;i<n;++i)
        {
            ans=max(ans,a[i]-a[i+1]);
        }
        cout<<ans<<'\n';
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
3 1 2 7 4



*/