#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 300 + 11;

int dp[N][N],a[N],k,dp1[N],dp2[N];
vector<int> v[N];

void dfs(int l, int pr)
{
    vector<int> vv;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) {dfs(v[l][j],l); vv.pb(v[l][j]);}
    for (int j=0; j<=k+1; j++)
        dp1[j]=0;
    if (vv.size()>0)
    {
        int to=vv[0];
        for (int d=0; d<=k; d++)
            dp1[d+1]=dp[to][d];
    }
    for (int j=1; j<vv.size(); j++)
    {
        for (int last=0; last<=k+1; last++)
    {
        for (int c=k; c>=0; c--)
        if (c+1+last>k)
            dp2[min(last,c+1)]=max(dp2[min(last,c+1)],dp1[last]+dp[vv[j]][c]);
    }
        for (int last=0; last<=k+1; last++)
        {
            dp1[last]=dp2[last];
            dp2[last]=0;
        }
    }
    for (int t=k; t>=0; t--)
    {
        if (t==0)
        {
            dp[l][t]=a[l];
            for (int j=0; j<vv.size(); j++)
                dp[l][t]+=dp[vv[j]][k];
        }
        dp[l][t]=max(dp[l][t],dp[l][t+1]);
        dp[l][t]=max(dp[l][t],dp1[t]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    int ans=0;
    for (int j=0; j<=k; j++)
        ans=max(ans,dp[1][j]);
    cout<<ans;
}