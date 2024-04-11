#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
const int inf=1e15;
void solve()
{
    int n;cin>>n;
    string s;
    cin>>s;
    s="#"+s;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    vector dp(n+1,vector<int>(2,-inf));
    //dp[i][0] 
    //dp[i][1] 
    if(s[1]=='1') dp[1][1]=a[1];
    else dp[1][0]=0;
    int ans=max(dp[1][0],dp[1][1]);
    for(int i=2;i<=n;++i)
    {
        if(s[i]=='1')
        {
            dp[i][1]=max(dp[i-1][1],dp[i-1][0])+a[i];
            dp[i][0]=dp[i-1][0]+a[i-1];
        }
        else
        {
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
        }
        ans=max(ans,max(dp[i][0],dp[i][1]));
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // red::__init();
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
/*
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/