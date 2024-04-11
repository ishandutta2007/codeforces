#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[405][405];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    int P=0;
    while(T--) {
        string s,t;
        cin>>s>>t;
        int n = s.size(), m = t.size();
        bool ok=0;
        for (int lim=0;lim<m;lim++) {
            for (int i = 0; i <= n; i++)for (int j = 0; j <= n; j++)dp[i][j] = -1e9;
            dp[0][lim]=0;
            for (int i=0;i<n;i++){
                for (int j=lim;j<=m;j++){
                    if (i>0)dp[i][j]=max(dp[i][j],dp[i-1][j]);
                    if (dp[i][j]<0)continue;
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                    if (s[i]==t[dp[i][j]]){
                        dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
                    }
                    if (j<m && s[i]==t[j]){
                        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
                    }
                }
            }
            for (int i=0;i<=n;i++)if (dp[i][m]>=lim)ok=1;
        }
        if (ok)cout<<"YES\n";
        else cout<<"NO\n";
    }
}