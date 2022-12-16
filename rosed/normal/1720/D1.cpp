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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n;
        cin>>n;

        vector<int> a(n);
        vector<int> dp(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            dp[i]=1;
        }
        int ans=1;
        for(int i=1;i<n;++i)
        {
            for(int j=max(0ll,j-512);j<i;++j)
            {
                if((a[j]^i)<(a[i]^j)) dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/