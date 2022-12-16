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
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            tot^=a[i];
        }
        if(n%2==0)
        {
            if(tot!=0)
            {
                cout<<"NO\n";
                return;
            }
            --n;
        }
        cout<<"YES\n";
        cout<<n-2<<'\n';
        for(int i=3;i<=n;i+=2) cout<<i-2<<' '<<i-1<<' '<<i<<'\n';
        for(int i=n-4;i>=1;i-=2) cout<<i<<' '<<i+1<<' '<<i+2<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/