#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,inf=2e9;
    int n,m;
    int a[N];
    bool vis[N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq; cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            cout<<2<<'\n';
            for(int i=1;i<=n;++i) vis[i]=0;
            for(int i=1;i<=n;++i)
            {
                for(int x=i;x<=n&&vis[x]==0;x*=2)
                {
                    cout<<x<<' ';
                    vis[x]=1;
                }
            }
            cout<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
5
5
6
7
8
9


*/