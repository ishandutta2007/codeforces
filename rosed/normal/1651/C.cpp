#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=1e9+7;
    int n;
    int a[N],b[N];
    int ans;
    inline int work()
    {
        int tmp1=inf,tmp2=inf,ans1=10*inf,ans2=10*inf;
        for(int i=1;i<=n;++i)
        {
            tmp1=min(tmp1,abs(a[1]-b[i]));
            tmp2=min(tmp2,abs(b[1]-a[i]));
        }
        ans1=min(abs(a[1]-b[1]),tmp1+tmp2);

        tmp1=tmp2=inf;
        for(int i=1;i<=n;++i)
        {
            tmp1=min(tmp1,abs(a[n]-b[i]));
            tmp2=min(tmp2,abs(b[n]-a[i]));
        }
        ans2=min(abs(a[n]-b[n]),tmp1+tmp2);
        //cout<<ans1<<' '<<ans2<<"!!!"<<endl;
        return ans1+ans2;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;ans=inf*100;
            for(int i=1;i<=n;++i) cin>>a[i];
            for(int i=1;i<=n;++i) cin>>b[i];
            ans=min(ans,work());
            reverse(b+1,b+n+1);
            ans=min(ans,work());
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
2
3
10 10 22
20 4 11
4
1 1 1 1
1000000000 1000000000 1000000000 1000000000

*/