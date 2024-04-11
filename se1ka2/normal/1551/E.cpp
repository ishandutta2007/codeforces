#include <iostream>
using namespace std;

int dp[2005][2005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[2005];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++) dp[i][j] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(a[i - 1] + j == i) dp[i][j] = dp[i - 1][j] + 1;
                else dp[i][j] = dp[i - 1][j];
            }
            for(int j = 1; j <= i; j++) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        }
        int ans = -1;
        for(int j = 0; j <= n; j++){
            if(dp[n][j] >= k){
                ans = j;
                break;
            }
        }
        cout << ans << endl;
    }
}