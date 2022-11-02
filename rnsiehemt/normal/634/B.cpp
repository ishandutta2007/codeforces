#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

ll s, x, dp[42][2];

int main()
{
    scanf("%lld%lld", &s, &x);
    dp[0][0] = 1;
    for (int i = 0; i < 40; i++) {
        if (s & (1ll << i)) {
            if (x & (1ll << i)) {
                dp[i+1][0] += dp[i][0] * 2;
            } else {
                dp[i+1][1] += dp[i][1];
                dp[i+1][0] += dp[i][1];
            }
        } else {
            if (x & (1ll << i)) {
                dp[i+1][1] += dp[i][1] * 2;
            } else {
                dp[i+1][0] += dp[i][0];
                dp[i+1][1] += dp[i][0];
            }
        }
    }
    if (s == x) dp[40][0] -= 2;
    printf("%lld\n", dp[40][0]);
}