#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
const int inf=1e18;
void solve()
{
    int n;
    cin>>n;
    vector a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            if(j==1||j==i) cout<<1<<' ';
            else cout<<0<<' ';
        }
        cout<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}