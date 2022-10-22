#include <bits/stdc++.h>

using namespace std;

long double getp(long long l, long long r) {
    long long a = 1;
    long long cnt = 0;
    for(int i = 0; i <= 18; i++, a *= 10ll) {
        long long b = a * 2 - 1;
        if(l > b || a > r)
            continue;

        cnt += min(r, b) - max(l, a) + 1;
    }

    return (long double)(cnt) / (r - l + 1);
}

int main() {
    int n;
    cin >> n;

    vector<long long> l(n), r(n);
    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    vector<vector<long double>> dp(n + 1, vector<long double>(n + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        long double p = getp(l[i], r[i]);
        //cout << p << endl;
        for(int j = 0; j < n; j++) {
            dp[i + 1][j + 1] += p * dp[i][j];
            dp[i + 1][j] += (1 - p) * dp[i][j];
        }
    }

    int k;
    cin >> k;
    long double ans = 0;
    for(int i = 0; i <= n; i++)
        if(i * 100 >= k * n)
            ans += dp[n][i];

    cout << setprecision(20) << fixed << ans;
}