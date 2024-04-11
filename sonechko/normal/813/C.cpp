#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 2e5 + 11;
const ll MOD = 1e18;
#define mod %MOD

int deep1[N],deep2[N],pref[N],use[N];
vector<int> v[N];
int n,m;
void dfs1(int l, int r)
{
    deep1[l]=0;
    pref[l]=r;
    deep2[l]=deep2[r]+1;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=r)
    {
        dfs1(v[l][j],l);
        deep1[l]=max(deep1[v[l][j]]+1,deep1[l]);
    }
}
void dfs2(int m, int d)
{
    use[m]=d;
    if (m==1) return;
    dfs2(pref[m],d+1);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    deep2[0]=-1;
    dfs1(1,0);
    dfs2(m,0);
    int ans=deep2[m]+deep1[m];
    for (int i=1; i<=n; i++)
    if (use[i]!=0&&use[i]<deep2[i])
    {
        ans=max(ans,deep2[i]+deep1[i]);
    }
    cout<<ans*2<<endl;
}