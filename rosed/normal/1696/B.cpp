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
    const int N=1e6+10,inf=2e9;
    int n,m,ans;
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n;
            ans=0;
            bool flag=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(a[i]==0) flag=0;
                else
                {
                    if(!flag) flag=1,++ans;
                }
            }
            if(ans>2) ans=2;
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
2.25 10 100

*/