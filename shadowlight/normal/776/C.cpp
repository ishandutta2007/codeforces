#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e15 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    long long n, k;
    cin >> n >> k;
    vector <long long> sum(n + 1, 0);
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum[i + 1] = x + sum[i];
    }
    vector <long long> min_zero(n + 1, -1);
    map <long long, long long> q;
    for (long long i = 1; i <= n; i++) {
        if (q[sum[i]] != 0) {
            min_zero[i] = q[sum[i]] + 1;
        } else if (!sum[i]) {
            min_zero[i] = 1;
        }
        q[sum[i]] = i;
    }
    vector <long long> dp(n + 1, 0);
    for (long long i = 1; i <= n; i++) {
        if (min_zero[i] == -1) continue;
        dp[i] = dp[min_zero[i] - 1] + 1;
    }
    long long now = 1;
    long long ans = 0;
    while (abs(now) < INF) {
        map <long long ,long long> q;
        for (long long i = 1; i <= n; i++) {
            if (q[sum[i] - now] != 0) {
                ans += dp[q[sum[i] - now]] + 1;
            } else if (sum[i] - now == 0) {
                ans++;
            }
            q[sum[i]] = i;
        }
        now *= k;
        if (now == 1) {
            break;
        }
    }
    cout << ans;
}