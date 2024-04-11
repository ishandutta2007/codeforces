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
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        int x;cin>>x;
        a[i]=x-a[i];
        sum+=a[i];
    }
    vector<vector<int> > eg(n+1);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        eg[x].emplace_back(y);
        eg[y].emplace_back(x);
    }

    vector<int> col(n+1);
    bool flag=0;
    int sum1=0,sum2=0;
    function<void(int,int)> dfs=[&](int now,int c) -> void
    {
        col[now]=c;
        if(c==2) sum1+=a[now];
        else sum2+=a[now];
        for(int t:eg[now])
        {
            if(col[t])
            {
                if(col[t]==c) flag=1;
            }
            else dfs(t,c^1);
        }
    };
    dfs(1,2);
    if(sum&1)
    {
        cout<<"NO\n";
        return;
    }
    if(sum1==sum2||flag) cout<<"YES\n";
    else cout<<"NO\n";
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