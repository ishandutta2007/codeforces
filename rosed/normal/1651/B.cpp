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
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            a[1]=1;
            bool flag=1;
            for(int i=2;i<=n;++i)
            {
                a[i]=a[i-1]*3;
                if(a[i]>1e9){flag=0;break;}
            }
            if(!flag){cout<<"NO\n";}
            else
            {
                cout<<"YES\n";
                for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
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

*/