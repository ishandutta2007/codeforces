#include <iostream>
using namespace std;
typedef long long ll;

ll a[1000006];
ll dp[1000006][2];

int main()
{
    ll n, r[3], d;
    cin >> n >> r[0] >> r[1] >> r[2] >> d;
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    dp[0][0] = r[0] * a[0] + r[2];
    dp[0][1] = min(r[0] * (a[0] + 1), r[1]);
    for(int i = 1; i < n - 1; i++){
        dp[i][0] = min(dp[i - 1][0] + r[0] * a[i] + r[2] + d,
                       dp[i - 1][1] + min(r[0] * (a[i] + 1), r[1]) + r[0] * 2 + d * 3);
        dp[i][1] = dp[i - 1][0] + min(r[0] * (a[i] + 1), r[1]) + d;
    }
    ll ans = dp[n - 2][0] + r[0] * a[n - 1] + r[2] + d;
    ans = min(ans, dp[n - 2][0] + min(r[0] * (a[n - 1] + 1), r[1]) + r[0] + d * 3);
    ans = min(ans, dp[n - 2][1] + min(r[0] * (a[n - 1] + 1), r[1]) + r[0] * 2 + d * 3);
    ans = min(ans, dp[n - 2][1] + r[0] * a[n - 1] + r[2] + r[0] + d * 2);
    cout << ans << endl;
}