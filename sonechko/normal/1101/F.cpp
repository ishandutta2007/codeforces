#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 400 + 11;
const int M = 3e5 + 11;

int dp[N][N];
int a[N];
vector<pair<int,pair<int,int> > > v[N];

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll ans=0;
    for (int i=1; i<=m; i++)
    {
        int l,r,k,c;
        cin>>l>>r>>c>>k;
        v[l].pb(mp(r,mp(k,c)));
        //int p=dp[l][r][k+1];
        //ans=max(ans,p*1ll*c);
    }
    for (int l=1; l<=n; l++)
    {
        for (int r=1; r<=n; r++)
        for (int p=0; p<=n+2; p++)
        {
            dp[r][p]=2e9;
            if (r==l) dp[r][p]=0;
        }
        for (int p=1; p<=n+2; p++)
        {
            int pos=l;
            for (int r=l+1; r<=n; r++)
            {
                while (pos<r&&max(dp[pos+1][p-1],a[r]-a[pos+1])<
                              max(dp[pos][p-1],a[r]-a[pos]))
                    pos++;
                dp[r][p]=max(dp[pos][p-1],a[r]-a[pos]);
            }
        }
        for (int j=0; j<v[l].size(); j++)
        {
            int p=dp[v[l][j].ff][v[l][j].ss.ff+1];
            ans=max(ans,p*1ll*v[l][j].ss.ss);
        }
    }
    cout<<ans<<endl;
}