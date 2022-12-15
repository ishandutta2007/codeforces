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
    string s;cin>>s;
    s=" "+s;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;j+=i)
        {
            if(s[j]=='1') break;
            if(s[j]=='0')
            {
                ans+=i;
                s[j]='2';
            }
        }
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