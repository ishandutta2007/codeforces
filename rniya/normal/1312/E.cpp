#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n),b(n);
    for (int i=0;i<n;++i) cin >> a[i];
    vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(n+1,{INF,-1}));
    for (int i=0;i<n;++i) dp[i][i+1]={1,a[i]};
    for (int j=2;j<=n;++j){
        for (int i=0;i+j<=n;++i){
            for (int k=1;k<j;++k){
                if (dp[i][i+k].first+dp[i+k][i+j].first<dp[i][i+j].first){
                    dp[i][i+j]={dp[i][i+k].first+dp[i+k][i+j].first,-1};
                }
                if (dp[i][i+k].first==1&&dp[i+k][i+j].first==1&&dp[i][i+k].second==dp[i+k][i+j].second){
                    dp[i][i+j]={1,dp[i][i+k].second+1};
                }
            }
        }
    }
    cout << dp[0][n].first << '\n';
}