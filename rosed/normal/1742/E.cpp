#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),b(n+1);
    for(int i=0;i<n;++i)
    {
        int x;cin>>x;
        if(i>0) a[i]=a[i-1];
        a[i]=max(a[i],x);
        b[i+1]=b[i];
        b[i+1]+=x;
    }
    a[n]=1e18;
    for(int i=1;i<=m;++i)
    {
        int x;cin>>x;
        int pos=upper_bound(a.begin(),a.end(),x)-a.begin();
        cout<<b[pos]<<' ';
    }
    cout<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}