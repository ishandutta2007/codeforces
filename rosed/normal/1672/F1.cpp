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
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n;
    int a[N],b[N],cnt[N];
    vector<int> eg[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            for(int i=0;i<=n+1;++i) cnt[i]=0,eg[i].clear();
            int maxn=0;
            for(int i=0;i<n;++i)
            {
                cin>>a[i];
                b[i]=a[i];
                maxn=max(maxn,++cnt[a[i]]);
            }
            sort(b,b+n);
            for(int i=0;i<n;++i)
            {
                eg[b[i]].emplace_back(b[(i+maxn)%n]);
            }
            for(int i=0;i<n;++i)
            {
                cout<<eg[a[i]].back()<<" \n"[i==n-1];
                eg[a[i]].pop_back();
            }
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
4
1 2 3 3
2 1 3 3
2 3 1 3

1 1 2 2
1 2 2 1

*/