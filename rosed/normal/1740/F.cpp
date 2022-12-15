#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=998244353;
const int inf=1e18;
const int N=2e5+10;
void solve()
{
    int n;
    cin>>n;
    vector dp(n+1,vector<int>(n+1));
    dp[0][0]=1;
    vector<int> c(n+1),t(n+1);
    for(int i=1,x;i<=n;++i) cin>>x,t[++c[x]]++;
    for(int i=1;i<=n;++i) t[i]+=t[i-1];
    for(int x=n;x;--x)//x
    {
        for(int i=1;i*x<=n;++i)//i
        {
            for(int k=i*x;k<=t[i];++k)//
            {
                (dp[i][k]+=dp[i-1][k-x])%=mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i) (ans+=dp[i][n])%=mod;
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/