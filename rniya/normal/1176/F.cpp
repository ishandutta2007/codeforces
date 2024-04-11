#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18;
const int MAX_K=2e5+10;

ll dp0[MAX_K][4][4],dp1[MAX_K][4][4];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<ll>> dp(n+1,vector<ll>(10,-INF));
    dp[0][0]=0;
    for (int i=0;i<n;++i){
        int K; cin >> K;
        for (int j=0;j<K+1;++j){
            for (int k=0;k<4;++k){
                for (int l=0;l<4;++l){
                    dp0[j][k][l]=-INF;
                    dp1[j][k][l]=-INF;
                }
            }
        }
        dp0[0][0][0]=dp1[0][0][0]=0;
        vector<pair<ll,int>> C;
        for (int j=0;j<K;++j){
            int c; ll d; cin >> c >> d;
            C.emplace_back(-d,c);
        }
        sort(C.begin(),C.end());
        for (int j=0;j<K;++j){
            int c=C[j].second; ll d=-C[j].first;
            for (int k=0;k<4;++k){
                for (int l=0;l<4;++l){
                    dp0[j+1][k][l]=max(dp0[j+1][k][l],dp0[j][k][l]);
                    dp1[j+1][k][l]=max(dp1[j+1][k][l],dp1[j][k][l]);
                    if (k+c<=3&&l+1<=3){
                        dp0[j+1][k+c][l+1]=max(dp0[j+1][k+c][l+1],dp0[j][k][l]+d);
                        dp1[j+1][k+c][l+1]=max(dp1[j+1][k+c][l+1],dp1[j][k][l]+d*(!l?2:1));
                    }
                }
            }
        }
        for (int j=0;j<10;++j){
            for (int k=0;k<4;++k){
                for (int l=0;l<4;++l){
                    if (j+l<10) dp[i+1][j+l]=max(dp[i+1][j+l],dp[i][j]+dp0[K][k][l]);
                    else dp[i+1][j+l-10]=max(dp[i+1][j+l-10],dp[i][j]+dp1[K][k][l]);
                }
            }
        }
    }
    ll ans=-INF;
    for (int j=0;j<10;++j) ans=max(ans,dp[n][j]);
    cout << ans << '\n';
}