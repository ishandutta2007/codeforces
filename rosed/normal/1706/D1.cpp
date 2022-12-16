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
    int ans;
    int a[N];
    inline void check(int maxn)
    {
        int minn=1e18;
        for(int i=1;i<=n;++i)
        {
            if(a[i]/m>maxn) return;
            int tmp=m;
            int l=1,r=m;
            while(l<=r)
            {
                if(a[i]/mid<=maxn) r=mid-1;
                else l=mid+1;
            }
            tmp=r+1;
            minn=min(minn,a[i]/tmp);
        }
        //cout<<maxn<<' '<<minn<<"!!"<<endl;
        ans=min(ans,maxn-minn);
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>m;
            ans=1e18;
            for(int i=1;i<=n;++i) cin>>a[i];
            
            for(int i=3000;i>=0;--i)
            {
                check(i);
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
5 2
4 5 6 8 11


*/