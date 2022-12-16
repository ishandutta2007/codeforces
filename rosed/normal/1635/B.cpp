#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,sum;
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;sum=0;
            for(int i=1;i<=n;++i) cin>>a[i];
            for(int i=2;i<n;++i)
            {
                if(a[i]>a[i-1]&&a[i]>a[i+1]) a[i+1]=max(a[i],a[i+2]),++sum;
            }
            cout<<sum<<'\n';
            for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
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