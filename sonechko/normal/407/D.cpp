#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 400 + 11;
const int MOD = 1e9 + 7;

int a[N][N],last[N],dp[N][N],pos[N*N];
vector<int> v[N*N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cin>>a[i][j];
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    dp[i][j]=m;
    int ans=0;
    for (int i=n; i>=1; i--)
    {
        for (int l=1; l<=m; l++)
        {
            v[a[i][l]].clear();
            pos[a[i][l]]=0;
        }
        for (int l=1; l<=m; l++)
        {
            if (v[a[i][l]].size()>0)
            {
                dp[i][v[a[i][l]].back()]=l-1;
            }
            v[a[i][l]].pb(l);
        }
        for (int j=1; j<=m; j++)
        for (int ii=i+1; ii<=n; ii++)
        {
            int x=a[ii][j];
            while (pos[x]<v[x].size()&&v[x][pos[x]]<=j)
                pos[x]++;
            if (pos[x]<v[x].size())
                dp[ii][j]=min(dp[ii][j],v[x][pos[x]]-1);
            if (pos[x]>0)
                dp[ii][v[x][pos[x]-1]]=min(dp[ii][v[x][pos[x]-1]],j-1);

        }
        for (int ii=i; ii<=n; ii++)
        for (int j=m; j>=1; j--)
        {
            if (j<m) dp[ii][j]=min(dp[ii][j],dp[ii][j+1]);
            if (ii>1) dp[ii][j]=min(dp[ii][j],dp[ii-1][j]);
            ans=max(ans,(ii-i+1)*(dp[ii][j]-j+1));
        }
///        cout<<i<<": "<<endl;
///        for (int i=1; i<=n; i++)
///        {
///            for (int j=1; j<=m; j++)
///            cout<<dp[i][j]<<" ";
///            cout<<endl;
///        }
        for (int l=1; l<=m; l++)
        {
            v[a[i][l]].clear();
            pos[a[i][l]]=0;
        }
    }
    cout<<ans<<endl;
}