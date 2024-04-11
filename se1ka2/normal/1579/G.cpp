#include <iostream>
using namespace std;

const int INF = 1000000000;

int dp[10002][1002];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[10005];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= 1000; j++) dp[i][j] = INF;
        }
        dp[0][0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= 1000; j++){
                if(j >= a[i]) dp[i + 1][j - a[i]] = min(dp[i + 1][j - a[i]], dp[i][j] + a[i]);
                else dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + a[i]);
                if(dp[i][j] >= a[i]){
                    if(dp[i][j] - a[i] <= j + a[i]){
                        if(dp[i][j] - a[i] <= 1000){
                            dp[i + 1][dp[i][j] - a[i]] = min(dp[i + 1][dp[i][j] - a[i]], j + a[i]);
                        }
                    }
                    else{
                        if(j + a[i] <= 1000){
                            dp[i + 1][j + a[i]] = min(dp[i + 1][j + a[i]], dp[i][j] - a[i]);
                        }
                    }
                }
                else dp[i + 1][0] = min(dp[i + 1][0], j + a[i]);
            }
        }
        int ans = INF;
        for(int j = 0; j <= 1000; j++) ans = min(ans, j + dp[n][j]);
        cout << ans << endl;
    }
}