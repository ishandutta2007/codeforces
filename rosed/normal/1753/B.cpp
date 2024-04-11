#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> cnt(m+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }
    bool flag=1;
    for(int i=1;i<m;++i)
    {
        cnt[i+1]+=cnt[i]/(i+1);
        cnt[i]%=(i+1);
        if(cnt[i]) flag=0;
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
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