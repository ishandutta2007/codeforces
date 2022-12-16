#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=998244353;
    int n,m;
    int a[N],b[N];
    int ans[N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;++i) ans[i]=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
            }
            int cnt=0,sum=0;
            for(int i=n;i>=1;--i)
            {
                if(a[i]>cnt)
                {
                    if(cnt!=m)
                    {
                        ++cnt;
                        ans[i]=1;
                    }
                    else ans[i]=0;
                }
                else ans[i]=1;
            }
            for(int i=1;i<=n;++i) cout<<ans[i];
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
1 1
1
2 1
1 2
3 1
1 2 1
4 2
1 4 3 1
5 2
5 1 2 4 3

1
4 2
1 1 3 4


*/