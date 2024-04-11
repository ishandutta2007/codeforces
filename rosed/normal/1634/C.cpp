#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=201314,inf=2e9;
    int n,m;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;
            if(m==1||n%2==0)
            {
                cout<<"YES\n";
                for(int i=1;i<=n;++i)
                {
                    for(int j=1,x=i;j<=m;++j,x+=n)
                    {
                        cout<<x<<' ';
                    }
                    cout<<'\n';
                }
            }
            else cout<<"NO\n";
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}