#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;

int a[N];
vector<int> v[N];
int dp[N];
int ans[N];

void dfs1(int l, int pr)
{
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        dfs1(v[l][j],l);
        dp[l]+=max(0,dp[v[l][j]]);
    }
    if (a[l]==1) dp[l]++; else dp[l]--;
}

void dfs2(int l, int pr, int mx)
{
    ans[l]=mx+dp[l];
    int res=mx;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) res+=max(0,dp[v[l][j]]);
    if (a[l]==1) res++; else res--;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
        {
            int res2=max(0,res-max(0,dp[v[l][j]]));
            dfs2(v[l][j],l,res2);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
}