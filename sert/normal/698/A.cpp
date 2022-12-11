#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.2
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
const int N = 1e6 + 34;
const int INF = 1e9 + 34;
typedef long long ll;

int n, dp[N][4], a[N];

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        dp[i + 1][2] = max(max(dp[i][0], dp[i][1]), dp[i][2]);
        if (a[i] & 1)
            dp[i + 1][0] = max(dp[i][1], dp[i][2]) + 1;
        if (a[i] & 2)
            dp[i + 1][1] = max(dp[i][0], dp[i][2]) + 1;
    }

    cout << n - max(max(dp[n][0], dp[n][1]), dp[n][2]);

    return 0;
}