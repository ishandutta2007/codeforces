#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int N = 5e4 + 11;

vector<int> v[N];
ll dp[N][501];
int n,k;
ll ans;


void dfs(int l, int pr)
{
    dp[l][0]=1;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        dfs(v[l][j],l);
        for (int d=0; d<=k-1; d++)
            ans+=(dp[l][d]*dp[v[l][j]][k-d-1]);
        for (int d=0; d<k; d++)
            dp[l][d+1]+=dp[v[l][j]][d];
    }
    //cout<<l<<": "<<dp[l][1]<<" "<<dp[l][2]<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    cout<<ans<<endl;
}