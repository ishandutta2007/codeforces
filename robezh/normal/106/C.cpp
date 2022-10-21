#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

int n,m,c0,d0;
int a[1050],b[1050],c[1050],d[1050];
int dp[12][1050];

int main(){
    cin >> n >> m >> c0 >> d0;
    for(int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    for(int i = 0; i <= m; i++) fill(dp[i], dp[i]+1050, -INF);
    dp[0][n] = 0;
    for(int i = 1; i <= m; i++){
        for(int k = 0; k <= a[i]/b[i]; k++){
            for(int j = n-k*c[i]; j >= 0; j--){
                if(dp[i-1][j+k*c[i]] != -INF){
                    dp[i][j] = max(dp[i][j], dp[i-1][j+k*c[i]] + d[i]*k);
                }
            }
        }
        for(int j = n; j >= 0; j--) dp[i][j] = max(dp[i-1][j], dp[i][j]);
    }
    int res = 0;
    for(int j = 0; j <= n; j++){
        res = max(res, dp[m][j] + j/c0*d0);
    }
    cout << res << endl;


}