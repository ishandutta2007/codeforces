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
    int a[N];
    int pre[N],suf[N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq=1;
        while(qwq--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(i!=1) pre[i]=pre[i-1]+max(0ll,a[i-1]-a[i]);
            }
            for(int i=n-1;i>=1;--i)
            {
                suf[i]=suf[i+1]+max(0ll,a[i+1]-a[i]);
            }
            for(int i=1;i<=m;++i)
            {
                int l,r;cin>>l>>r;
                if(l<=r) cout<<pre[r]-pre[l]<<'\n';
                else
                {


                    cout<<suf[r]-suf[l]<<'\n';
                }
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


*/