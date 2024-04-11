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
    const int N=1e6+10,mod=1e4+7,inf=2e9;
    int n,m,tot;
    int a[N],c[N],num;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            num=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
            }
            int t=1;
            if(n%2==1) c[++num]=a[t++];
            for(;t<=n;t+=2)
            {
                c[++num]=min(a[t],a[t+1]);
                c[++num]=max(a[t],a[t+1]);
            }
            bool flag=1;
            for(int i=2;i<=num;++i)
            {
                if(c[i-1]>c[i]) flag=0;
            }
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
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