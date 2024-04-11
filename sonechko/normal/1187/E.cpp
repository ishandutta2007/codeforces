#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 11;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

vector<int> v[N];
ll dp[N],sz[N],ans,n;

void dfs(int l, int pr)
{
    dp[l]=0;
    sz[l]=1;
    for (int i=0; i<v[l].size(); i++)
        if (v[l][i]!=pr)
    {
        dfs(v[l][i],l);
        dp[l]+=dp[v[l][i]];
        sz[l]+=sz[v[l][i]];
    }
    dp[l]+=sz[l];
}

void dfss(int l, int pr, ll dpp)
{
    ans=max(ans,dp[l]+dpp+(n-sz[l]));
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfss(v[l][j],l,dp[l]-dp[v[l][j]]-sz[v[l][j]]
                          +dpp+(n-sz[l]));

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    dfss(1,0,0);
    cout<<ans<<endl;
}
/**
1 7 1 4 4 5 6
1 1 4 4 5 7 6

5|
------
7|

**/