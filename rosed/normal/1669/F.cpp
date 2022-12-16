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
    int n,m,ans;
    int a[N],pre[N],suf[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;ans=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                pre[i]=pre[i-1]+a[i];
            }
            suf[n+1]=0;
            for(int i=n;i>=1;--i) suf[i]=suf[i+1]+a[i];
            int l=0;
            for(int r=n;r>=1;--r)
            {
                while(l<r&&pre[l+1]<=suf[r]) ++l;
                if(l>=r) break;
                if(pre[l]==suf[r]) ans=max(ans,l+n-r+1);
                //cout<<l<<' '<<r<<"!!"<<endl;
            }
            cout<<ans<<'\n';
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
1 2 3 4

*/