#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit ((i)&(-i))
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> val,tmp;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(!a[i]) tmp.emplace_back(i);
        else val.emplace_back(i);
    }
    int ans=0;
    int now=0,tot=val.size();
    while(tmp.size()>0&&now<tot)
    {
        if(val[now]>tmp.back()) break;
        ++now;
        tmp.pop_back();
        ++ans;
    }
    cout<<ans<<'\n';
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}