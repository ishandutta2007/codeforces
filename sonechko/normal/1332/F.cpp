#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 3e5 + 11;
const ll MOD = 998244353;

vector<int> v[N];
ll dp[N][2][2];
ll dpp[N];
ll ans;

void dfs(int l, int pr)
{
    dp[l][0][0]=1;
    dp[l][1][0]=1;
    dp[l][0][1]=1;
    dp[l][1][1]=1;
    dpp[l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        dfs(v[l][j],l);
        int to=v[l][j];
        dp[l][0][0]=(dp[l][0][0]*(dp[to][0][0]+dp[to][1][0]+dp[to][1][1]))%MOD;
        dp[l][0][1]=(dp[l][0][1]*
                (dp[to][0][0]+dp[to][1][0]+dp[to][1][1]))%MOD;
        dp[l][1][0]=(dp[l][1][0]*
                (dp[to][0][0]+dp[to][0][1]+dp[to][1][0]+dp[to][1][1]+
                 dp[to][0][0]+dp[to][1][0]+dp[to][1][1]))%MOD;
        dp[l][1][1]=(dp[l][1][1]*
                (dp[to][0][0]+dp[to][1][0]+
                 dp[to][0][0]+dp[to][1][0]+dp[to][1][1]))%MOD;
        dpp[l]=(dpp[l]*1ll*(dpp[to]+1))%MOD;
    }
    dp[l][1][0]=(dp[l][1][0]-dp[l][0][0]+MOD)%MOD;
    dp[l][1][1]=(dp[l][1][1]-dp[l][0][1]+MOD)%MOD;

    dpp[l]--;

    dpp[l]=(dpp[l]+dp[l][1][1]+dp[l][1][0])%MOD;
    ///cout<<l<<": "<<dp[l][0][0]<<" "<<dp[l][0][1]<<" "<<dp[l][1][0]<<" "<<dp[l][1][1]<<endl;
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
    cout<<dpp[1]<<"\n";
}