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
    const int N=5e5+10,mod=998244353,inf=2e9;
    int n,m;
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;
            int sum=0;
            int maxn=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                maxn=max(maxn,a[i]);
                if(i>1)
                {
                    sum+=abs(a[i]-a[i-1]);
                }
            }
            int tmp1=min(a[1]-1,a[n]-1),tmp2=min(abs(a[1]-m),abs(a[n]-m));

            if(maxn>=m) tmp2=0;
            for(int i=1;i<n;++i)
            {
                tmp1=min(tmp1,abs(a[i]-1)+abs(a[i+1]-1)-abs(a[i]-a[i+1]));
                tmp2=min(tmp2,abs(a[i]-m)+abs(a[i+1]-m)-abs(a[i]-a[i+1]));
            }
            cout<<sum+tmp1+tmp2<<'\n';
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
3 5
8 2 5

*/