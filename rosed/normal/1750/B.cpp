#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-9)
void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    s="#"+s;
    int sum1=0,sum2=0;
    vector<int> pre(n+1),nxt(n+1);
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='0') ++sum1;
        else ++sum2;
        if(i==1||s[i]!=s[i-1]) pre[i]=i;
        else pre[i]=pre[i-1];
    }
    for(int i=n;i>=1;--i)
    {
        if(i==n||s[i]!=s[i+1]) nxt[i]=i;
        else nxt[i]=nxt[i+1];
    }
    int ans=sum1*sum2;
    for(int i=1;i<=n;++i)
    {
        ans=max(ans,(nxt[i]-pre[i]+1)*(nxt[i]-pre[i]+1));
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}