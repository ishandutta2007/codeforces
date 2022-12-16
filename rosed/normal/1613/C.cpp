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
        int n,m;
        cin>>n>>m;
        vector<int> tim(n);
        for(int i=0;i<n;++i)
        {
            cin>>tim[i];
        }
        auto check=[&](int x) -> bool
        {
            int sum=x;
            for(int i=0;i<n-1;++i)
            {
                sum+=min(x,tim[i+1]-tim[i]);
            }
            return sum>=m;
        };
        int l=1,r=1e18;
        while(l<=r)
        {
            if(check(mid)) r=mid-1;
            else l=mid+1;
        }
        cout<<r+1<<'\n';
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
1 2 5 10

*/