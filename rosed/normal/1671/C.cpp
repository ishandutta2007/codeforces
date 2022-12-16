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
    int n,m,sum;
    int a[N],s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;
            sum=0;
            for(int i=1;i<=n;++i) cin>>a[i];
            sort(a+1,a+n+1);
            for(int i=1;i<=n;++i)
            {
                s[i]=s[i-1]+a[i];
            }
            for(int t=0;;)
            {
                int l=1,r=n;
                while(l<=r)
                {
                    if(s[mid]+mid*t<=m) l=mid+1;
                    else r=mid-1;
                }
                int k=l-1;
                if(!k) break;
                int d=m-(s[k]+k*t);
                d=d/k+1;
                sum+=k*d;
                t+=d;
            }
            cout<<sum<<'\n';
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