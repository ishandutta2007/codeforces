#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 1000000000;

int main()
{
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        int t[202];
        for(int i = 0; i < n; i++) cin >> t[i];
        sort(t, t + n);
        int dp[402][202];
        for(int j = 1; j <= n; j++) dp[0][j] = INF;
        dp[0][0] = 0;
        for(int i = 1; i <= 400; i++){
            for(int j = 0; j <= n; j++) dp[i][j] = dp[i - 1][j];
            for(int j = 1; j <= n; j++) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(i - t[j - 1]));
        }
        cout << dp[400][n] << endl;
    }
}