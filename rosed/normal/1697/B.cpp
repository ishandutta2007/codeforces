#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    int a[N];
    int s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            if(x>n)
            {
                cout<<0<<'\n';
                continue;
            }
            cout<<s[n-(x-y)]-s[n-x]<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
1
1 2 3
a
aa

*/