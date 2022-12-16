#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e6+10,mod=1e9+7,inf=2e9;
    int n;
    int a[N];
    int pre[2];
    inline void main()
    {   
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            bool flag=1;
            for(int i=1;i<=n;++i) cin>>a[i];
            pre[0]=pre[1]=0;
            for(int i=1;i<=n;++i)
            {
                int b=a[i]&1;
                if(a[i]<pre[b]) flag=0;
                pre[b]=a[i];
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