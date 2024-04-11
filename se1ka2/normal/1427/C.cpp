#include <iostream>
using namespace std;

const int INF = 100000000;

int main()
{
    int r, n;
    cin >> r >> n;
    int t[100005], x[100005], y[100005];
    int dp[100005];
    for(int i = 0; i <= n; i++) dp[i] = -INF;
    int s = -INF;
    dp[0] = 0;
    t[0] = 0, x[0] = 1, y[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> x[i] >> y[i];
        dp[i] = max(dp[i], s + 1);
        for(int j = max(0, i - 1000); j < i; j++){
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        if(i >= 1000) s = max(s, dp[i - 1000]);
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}