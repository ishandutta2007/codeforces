#include <iostream>
using namespace std;

int dp[100002][2];

int main()
{
    int n, m;
    cin >> n >> m;
    int a[100002];
    a[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = m;
    for(int i = 1; i <= n + 1; i++){
        if(i % 2){
            dp[i][0] = dp[i - 1][0] + a[i] - a[i - 1];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i] - a[i - 1] - 1);
        }
        else{
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1] + a[i] - a[i - 1], dp[i - 1][0] + a[i] - a[i - 1] - 1);
        }
    }
    cout << max(dp[n + 1][0], dp[n + 1][1]) << endl;
}