#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 3e5 + 11;

vector<int> v[N];
int ans;
int dp[N][3];

void dfs(int l, int pr)
{
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs(v[l][j],l);
    dp[l][0]=1;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dp[l][0]+=min(min(dp[v[l][j]][0],dp[v[l][j]][1]),dp[v[l][j]][2]);
    dp[l][1]=0;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dp[l][1]+=min(dp[v[l][j]][0],dp[v[l][j]][2]);
    dp[l][2]=2e9;
    int x=0;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) x+=min(dp[v[l][j]][0],dp[v[l][j]][2]);
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dp[l][2]=min(dp[l][2],
            x-min(dp[v[l][j]][0],dp[v[l][j]][2])+dp[v[l][j]][0]);
    ///cout<<l<<" "<<dp[l][0]<<" "<<dp[l][1]<<" "<<dp[l][2]<<endl;
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
    }
    dfs(1,0);
    int ans=0;
    for (int j=0; j<v[1].size(); j++)
        ans+=dp[v[1][j]][0]-1;
    cout<<ans<<"\n";
}