#include <iostream>
using namespace std;
typedef long long ll;

ll dp[300005][3];

int main()
{
    ll n, x;
    cin >> n >> x;
    ll a[300005];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        dp[i][0] = max(0ll, dp[i - 1][0] + a[i - 1]);
        dp[i][1] = max(dp[i][0], dp[i - 1][1] + a[i - 1] * x);
        dp[i][2] = max(dp[i][1], dp[i - 1][2] + a[i - 1]);
        ans = max(ans, dp[i][2]);
    }
    cout << ans << endl;
}