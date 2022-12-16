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
    int a[N];
    int tl,tr;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            int sum=0;
            tl=n,tr=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
            }
            for(int l=1;l<=n;++l)
            {
                int r=l;
                while(r<n&&a[r+1]==a[l]) ++r;
                if(r-l+1>=2) tl=min(tl,l),tr=max(tr,r);
                l=r;
            }
            if(tl>tr) cout<<0<<'\n';
            else
            {
                int sum=tr-tl+1-2;
                if(sum<=1) cout<<sum<<'\n';
                else cout<<sum-1<<'\n';
                //cout<<sum-1<<'\n';
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
5
1 2
2 3
3 4
3 5

*/