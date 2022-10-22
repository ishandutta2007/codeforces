#include <iostream>
using namespace std;

const int INF = 1000000000;

int dp[5005][5005];

int main()
{
    int n;
    cin >> n;
    int k = 0;
    int a[5005];
    int x[5005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]) x[k++] = i;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++) dp[i][j] = INF;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++) dp[i][j] = dp[i - 1][j];
        if(a[i - 1]) continue;
        for(int j = 1; j <= k; j++) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(i - 1 - x[j - 1]));
    }
    cout << dp[n][k] << endl;
}