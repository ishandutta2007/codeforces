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
    typedef array<int,2> pr;
    vector<pr> a(m+1);
    for(int i=1;i<=m;++i)
    {
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=1;i<=m;++i)
    {
        vector dp(n+1,vector<int>(n+1,0));
        for(int k=1;k<=m;++k) if(i!=k)
        {
            int x=a[k][0],y=a[k][1];
            for(int j=1;j<=n;++j) dp[x][j]=dp[j][y]=1;
        }
        bool flag=0;
        for(int x=1;x<=n;++x)
        {
            for(int y=1;y<=n;++y)
            {
                int b1=(x==a[i][0]),b2=(y==a[i][1]);
                if((b1^b2)&&!dp[x][y]) flag=1;
            }
        }
        if(flag)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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