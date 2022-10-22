#include <iostream>
using namespace std;

int a[200005];
int dp[200005][2];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = n;
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + a[i - 1];
            if(i > 1){
                dp[i][0] = min(dp[i][0], dp[i - 2][1]);
                dp[i][1] = min(dp[i][1], dp[i - 2][0] + a[i - 2] + a[i - 1]);
            }
        }
        cout << min(dp[n][0], dp[n][1]) << endl;
    }
}