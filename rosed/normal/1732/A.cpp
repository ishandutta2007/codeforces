#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7,inf=1e15;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    int g;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(i==1) g=a[1];
        else g=__gcd(g,a[i]);
    }
    int ans=inf;
    vector<int> dp(21,inf);
    for(int i=n;i>=1;--i)
    {
        dp[i]=min(dp[i],n-i+1);
        for(int k=1;k<=20;++k)
        {
            int t=__gcd(i,k);
            dp[t]=min(dp[t],dp[k]+n-i+1);
        }
    }
    if(g==1)
    {
        cout<<0<<'\n';
        return;
    }
    for(int i=1;i<=20;++i)
    {
        if(__gcd(g,i)==1) ans=min(ans,dp[i]);
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/