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
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n;
    int a[N];
    int sum;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;sum=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(a[i]<0) ++sum,a[i]=-a[i];
            }
            for(int i=1;i<=sum;++i) a[i]=-a[i];
            bool flag=0;
            for(int i=2;i<=n;++i)
            {
                if(a[i]<a[i-1]) flag=1;
            }
            if(!flag) cout<<"YES\n";
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