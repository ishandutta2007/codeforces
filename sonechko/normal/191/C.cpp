#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5 + 11;

vector<int> v[N],w[N];
int d[20][N];
int deep[N],dp[N];
int ans[N];
int tin[N],tout[N],timee;

void dfs(int l, int pr)
{
    timee++;
    tin[l]=timee;
    deep[l]=deep[pr]+1;
    d[0][l]=pr;
    for (int j=1; j<20; j++)
        d[j][l]=d[j-1][d[j-1][l]];
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs(v[l][j],l);
    tout[l]=timee;
}

void dfs2(int l, int pr)
{
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        dfs2(v[l][j],l);
        dp[l]+=dp[v[l][j]];
    }
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]==pr) ans[w[l][j]]=dp[l];
}

bool pred(int l, int r)
{
    return (tin[l]<=tin[r]&&tout[r]<=tout[l]);
}

int lca(int l, int r)
{
    if (pred(l,r)) return l;
    if (pred(r,l)) return r;
    for (int j=19; j>=0; j--)
        if (d[j][l]!=0&&(!pred(d[j][l],r))) l=d[j][l];
    return d[0][l];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
        w[l].pb(i);
        w[r].pb(i);
    }
    dfs(1,0);
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        int k=lca(l,r);
        dp[l]++;
        dp[r]++;
        dp[k]-=2;
    }
    dfs2(1,0);
    for (int i=1; i<n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}