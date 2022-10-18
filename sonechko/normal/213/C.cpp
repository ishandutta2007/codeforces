#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 300 + 11;

int dp[N*2][N][N];
int a[N][N],num[N][N];
vector<pair<int,int> > v[N*2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        cin>>a[i][j];
        int t=i+j-1;
        v[t].pb(mp(i,j));
        num[i][j]=v[t].size();
    }
    dp[1][1][1]=a[1][1];
    dp[1][0][0]=-1e9;
    dp[1][0][1]=-1e9;
    dp[1][1][0]=-1e9;
    for (int d=2; d<=n+n-1; d++)
    {
        for (int i=0; i<v[d].size(); i++)
        {
            dp[d][0][i+1]=-1e9;
            dp[d][i+1][0]=-1e9;
            dp[d][0][0]=-1e9;
        }
        for (int i=0; i<v[d].size(); i++)
        for (int j=0; j<v[d].size(); j++)
        {
        int l1=v[d][i].ff;
        int r1=v[d][i].ss;
        int l2=v[d][j].ff;
        int r2=v[d][j].ss;
        int ans=max({
                    dp[d-1][num[l1-1][r1]][num[l2-1][r2]],
                    dp[d-1][num[l1-1][r1]][num[l2][r2-1]],
                    dp[d-1][num[l1][r1-1]][num[l2-1][r2]],
                    dp[d-1][num[l1][r1-1]][num[l2][r2-1]]
                    });
        if (l1==l2&&r1==r2) dp[d][i+1][j+1]=ans+a[l1][r1];
        else dp[d][i+1][j+1]=ans+a[l1][r1]+a[l2][r2];
        }
    }
    cout<<dp[n+n-1][1][1]<<"\n";
}