#include <bits/stdc++.h>
using namespace std;
const int INF=1e9,MAX_N=16;

int dp[1<<MAX_N][MAX_N][MAX_N];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin >> a[i][j];
    vector<vector<int>> diff1(n,vector<int>(n,INF)),diff2(n,vector<int>(n,INF));
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            for (int k=0;k<m;++k)
                diff1[i][j]=min(diff1[i][j],abs(a[i][k]-a[j][k]));
            for (int k=0;k<m-1;++k)
                diff2[i][j]=min(diff2[i][j],abs(a[i][k+1]-a[j][k]));
        }
    }
    if (n==1){cout << diff2[0][0] << '\n'; return 0;}
    for (int mask=0;mask<(1<<n);++mask){
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                for (int k=0;k<n;++k) if (!(mask&1<<k)){
                    if (!mask) dp[mask|1<<k][k][k]=INF;
                    if ((mask|1<<k)!=(1<<n)-1) dp[mask|1<<k][i][k]=max(dp[mask|1<<k][i][k],min(dp[mask][i][j],diff1[j][k]));
                    else dp[mask|1<<k][i][k]=max(dp[mask|1<<k][i][k],min({dp[mask][i][j],diff1[j][k],diff2[i][k]}));
                }
            }
        }
    }
    int ans=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            ans=max(ans,dp[(1<<n)-1][i][j]);
    cout << ans << '\n';
}