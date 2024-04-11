#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
#define ll long long
#define ss second
#define ff first
#define ld long double
#define pb push_back
int use[N],pred[N],lc[20][N],deep[N];
vector<int> v[N];
void dfs(int l, int r)
{
    use[l]=1;
    deep[l]=r;
    for (int i=0; i<v[l].size(); i++)
        if (use[v[l][i]]==0)
    {
        pred[v[l][i]]=l;
        dfs(v[l][i],r+1);
    }
}
int lca(int l, int r)
{
    if (l==r) return l;
    for (int i=19; i>=0; i--)
    {
        int ps=lc[i][l];
        if (deep[ps]>=deep[r]) l=ps;
    }
    for (int i=19; i>=0; i--)
    {
        int ps=lc[i][r];
        if (deep[ps]>=deep[l]) r=ps;
    }
    if (l==r) return l;
    for (int i=19; i>=0; i--)
    {
        int ps1=lc[i][l],ps2=lc[i][r];
        if (ps1!=ps2) {l=ps1; r=ps2;}
    }
    return pred[l];
}
int get(int a, int b1, int b2)
{
    int p1=lca(a,b1),p2=lca(a,b2);
    if (p1==a&&p2==a)
    {
        int d=lca(b1,b2);
        return deep[d]-deep[a]+1;
    }
    if (p1==a||p2==a){return 1;}
    if (p1==p2) return
    deep[lca(b1,b2)]-deep[p1]+1+deep[a]-deep[p1];
    return deep[a]-max(deep[p1],deep[p2])+1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=2; i<=n; i++)
    {
        int l;
        cin>>l;
        v[l].pb(i);
        v[i].pb(l);
    }
    dfs(1,1);
    for (int i=1; i<=n; i++)
    lc[0][i]=pred[i];
    for (int j=1; j<20; j++)
    for (int i=1; i<=n; i++)
    lc[j][i]=lc[j-1][lc[j-1][i]];
    for (int j=1; j<=m; j++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int ans=0;
        ans=max(ans,get(l,r,k));
        ans=max(ans,get(r,l,k));
        ans=max(ans,get(k,r,l));
        cout<<ans<<"\n";
    }
}