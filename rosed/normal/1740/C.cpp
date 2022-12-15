#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7;
const int inf=1e18;
const int N=2e5+10;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    int ans=max(a[n]-a[1]+a[n]-a[n-1],a[n]-a[1]+a[2]-a[1]);
    for(int i=2;i<=n;++i)
    {
        ans=max(ans,a[i]-a[1]+a[i]-a[i-1]);
        ans=max(ans,a[n]-a[i-1]+a[i]-a[i-1]);
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