#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e4 + 5;
int dp[105][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i <= n; i++)
        fill(dp[i], dp[i] + MAXN, -10000000);
    dp[0][0] = 0;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        int b, a;
        cin >> b >> a;
        for(int k = n; k >= 1; k--)
            for(int su = 10000; su >= a; su--)
                dp[k][su] = max(dp[k][su], dp[k - 1][su - a] + b);
        tot += a;
    }
    for(int k = 1; k <= n; k++) {
        double ans = -1.0;
        for(int su = 0; su <= tot; su++) {
            if(dp[k][su] >= 0)
                ans = max(ans, min((double)dp[k][su], (double)(tot + su)/2.0));
        }
        cout << fixed << setprecision(6) << ans << '\n';
    }
}