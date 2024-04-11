#include<bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll unsigned long long
const int N = 1e3 + 10;
int a[N],b[N],k,pref[N],use[N],dp[N][N],ft,masa[N],krasa[N];
bool p[N];
vector<int> v[N],g;
void dfs(int l)
{
    g.pb(l);
    pref[g.size()-1]=k;
    use[l]=1;
    p[ft]=0;
    p[l]=1;
    masa[l]=masa[ft]+a[l];
    krasa[l]=krasa[ft]+b[l];
    ft=l;
    for (int i=0; i<v[l].size(); i++)
    if (use[v[l][i]]==0) dfs(v[l][i]);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,w;
    cin>>n>>m>>w;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    for (int i=1; i<=n; i++)
    cin>>b[i];
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    g.pb(0);
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        k=g.size()-1;
        ft=i;
        dfs(i);
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        for (int j=0; j<=w; j++)
    {
        dp[i][j]=dp[i-1][j];
        int to=g[i];
        if (a[to]<=j) dp[i][j]=max(dp[i][j],dp[pref[i]][j-a[to]]+b[to]);
        if (p[to]&&masa[to]<=j) dp[i][j]=max(dp[i][j],dp[pref[i]][j-masa[to]]+krasa[to]);
        ans=max(ans,dp[i][j]);
    }
    cout<<ans<<endl;
}