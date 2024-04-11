#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    long long dp[n];
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
    }

    for (int i = 0; i < k; ++i) {
        long long v[n];
        fill(v, v + n, 0ll);

        for (int i = 0; i < n; ++i) {
            
            long long s = 0;
            for (int x = a[i] - 1; x >= 0; x &= x + 1, --x) {
                s += v[x];
            }
            for (int x = a[i]; x < n; x |= x + 1) {
                v[x] += dp[i];
            }
            dp[i] = s;
        }
    }

    cout << accumulate(dp, dp + n, 0ll) << "\n";
}