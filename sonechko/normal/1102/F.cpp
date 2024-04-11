#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e4 + 11;
const int MOD = 1e9 + 7;

int a[20][15000],dp1[30][30],dp2[30][30],dp[17][17][66000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>a[i][j];
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        dp1[i][j]=2e9;
        dp2[i][j]=2e9;
        for (int t=1; t<=m; t++)
            dp1[i][j]=min(dp1[i][j],abs(a[i][t]-a[j][t]));
        for (int t=1; t<m; t++)
            dp2[i][j]=min(dp2[i][j],abs(a[i][t+1]-a[j][t]));
    }
    for (int mask=1; mask<(1<<n); mask++)
    for (int fir=1; fir<=n; fir++)
    if (mask&(1<<(fir-1)))
    for (int last=1; last<=n; last++)
    if (mask&(1<<(last-1)))
    {
        if (fir==last&&mask==(1<<(last-1))) dp[fir][last][mask]=2e9; else
            {
                dp[fir][last][mask]=0;
                for (int pred=1; pred<=n; pred++)
                    if (pred!=last&&(mask&(1<<(pred-1))))
                {
                    dp[fir][last][mask]=max(dp[fir][last][mask],
                        min(dp[fir][pred][(mask^(1<<(last-1)))],dp1[pred][last])
                                        );
                }
            }
    }
    int ans=0;
    for (int fir=1; fir<=n; fir++)
    for (int last=1; last<=n; last++)
    ans=max(ans, min(dp[fir][last][(1<<n)-1],dp2[fir][last]));
    cout<<ans<<endl;
}