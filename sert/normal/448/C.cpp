#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;

int dp[N][N], t;
int a[N];
int n;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > n)
            a[i] = n + 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n + 1; j++)
            dp[i][j] = N * N;

    dp[0][0] = 1;
    dp[0][a[0]] = a[0];

    for (int i = 0; i < n - 1; i++)
    for (int h = 0; h <= n + 1; h++) {
        if (dp[i][h] == N * N)
            continue;
        t = a[i + 1];
        if (t <= h) {
            dp[i + 1][t] = min(dp[i + 1][t], dp[i][h]);
            continue;
        }

        dp[i + 1][h] = min(dp[i + 1][h], dp[i][h] + 1);
        dp[i + 1][t] = min(dp[i + 1][t], dp[i][h] + t - h);
    }
    int ans = N * N;
    for (int i = 0; i <= n + 1; i++)
        ans = min(ans, dp[n - 1][i]);

    cout << ans;



    return 0;
}