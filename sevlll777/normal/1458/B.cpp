#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
int dp[102][10109];
int dp2[102][10109];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(1 + n), B(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i] >> B[i];
    int p = 0;
    for (auto x : B) p += x;
    int suma = 0;
    for (auto x: A) suma += x;
    dp[0][0] = 1e6 + p;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= i; k++) {
            for (int sum = 0; sum <= suma; sum++) {
                dp2[k][sum] = dp[k][sum];
                if (sum >= A[i]) {
                    int d = dp[k - 1][sum - A[i]];
                    d += B[i];
                    if (d > dp2[k][sum]) {
                        dp2[k][sum] = d;
                    }
                }
            }
        }
        for (int k = 1; k <= n; k++) {
            for (int sum = 0; sum <= suma; sum++) {
                dp[k][sum] = dp2[k][sum];
                dp2[k][sum] = 0;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        int kek = 0;
        for (int sum = 0; sum <= suma; sum++) {
            kek = max(kek, min(2 * sum, dp[k][sum] - 1000000));
        }
        cout << fixed << setprecision(17) << 1.0 * kek / 2 << ' ';
    }
    cout << '\n';
}