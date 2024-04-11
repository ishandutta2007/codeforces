#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 5000 + 11;

int mx[N],a[N],b[N],c[N];
vector<int> v[N];
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i]>>c[i];
    for (int i=1; i<=n; i++)
        mx[i]=i;
    for (int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        mx[y]=max(mx[y],x);
    }
    for (int i=1; i<=n; i++)
        v[mx[i]].pb(c[i]);
    for (int i=1; i<=n; i++)
    {
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
    }
    for (int i=0; i<=n; i++)
    for (int j=0; j<=5000; j++)
    dp[i][j]=-1;
    dp[0][k]=0;
    for (int i=1; i<=n; i++)
    for (int j=0; j<=5000; j++)
        if (dp[i-1][j]!=-1&&j>=a[i])
    {
        int t=j+b[i],ss=dp[i-1][j];
        dp[i][t]=max(dp[i][t],ss);
        ///cout<<"! "<<i-1<<" "<<t<<" "<<ss<<endl;
        for (int x=0; x<v[i].size(); x++)
        {
            if (t==0) break;
            t--;
            ss+=v[i][x];
            ///cout<<i<<" "<<t<<" "<<ss<<endl;
            dp[i][t]=max(dp[i][t],ss);
        }
    }
    int ans=-1;
    for (int d=0; d<=5000; d++)
        ans=max(ans,dp[n][d]);
    cout<<ans<<"\n";
}
/**

**/