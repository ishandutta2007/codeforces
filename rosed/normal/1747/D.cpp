#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
void solve()
{
    int n,m;cin>>n>>m;
    vector<int> a(n+1),s(n+1);
    map<int,set<int>> q[2];
    vector<int> pre(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]) pre[i]=i;
        else pre[i]=pre[i-1];
        s[i]=s[i-1]^a[i];
        q[i&1][s[i]].insert(i);
    }
    // cout<<s[6]<<' '<<s[3]<<"!!"<<endl;
    for(int i=1;i<=m;++i)
    {
        int l,r;cin>>l>>r;
        if(pre[r]<l)
        {
            cout<<0<<'\n';
            continue;
        }
        if(s[r]!=s[l-1])
        {
            cout<<"-1\n";continue;
        }
        if(((r-l+1)&1)||a[l]==0||a[r]==0)
        {
            cout<<1<<'\n';continue;
        }
        int b=r&1;
        auto it=q[b^1][s[r]].lower_bound(l);
        if(it==q[b^1][s[r]].end()||(*it)>r)
        {
            cout<<"-1\n";continue;
        }
        else cout<<2<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}