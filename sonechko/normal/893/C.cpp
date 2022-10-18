#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ll long long
#define ss second
const int N = 1e5 + 11;
pair<int,int> a[N];
int use[N];
vector<int> v[N];
void dfs(int l)
{
    use[l]=1;
    for (int i=0; i<v[l].size(); i++)
        if (use[v[l][i]]==0) dfs(v[l][i]);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].ff;
        a[i].ss=i;
    }
    sort(a+1,a+n+1);
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    ll ans=0;
    for (int i=1; i<=n; i++)
        if (use[a[i].ss]==0)
    {
        dfs(a[i].ss);
        ans+=1LL*a[i].ff;
    }
    cout<<ans<<endl;
}