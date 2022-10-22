#include <iostream>
using namespace std;

int dp[200003][3];

int main()
{
    int k[3];
    int a[3][200003];
    int b[200003];
    for(int i = 0; i < 3; i++) cin >> k[i];
    int n = k[0] + k[1] + k[2];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < k[i]; j++){
            cin >> a[i][j];
            b[a[i][j]] = i;
        }
    }
    for(int i = 1; i <= n; i++){
        if(b[i] == 0){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
            dp[i][2] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + 1;
        }
        if(b[i] == 1){
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][2] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + 1;
        }
        if(b[i] == 2){
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
            dp[i][2] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
        }
    }
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;
}