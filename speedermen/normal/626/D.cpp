#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int MD = 1000000007;

#define ld long double

ld dp[4][6 * N], F[N];
int n, A[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    ld total = n * (n - 1) / 2.0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (A[i] > A[j])
                F[A[i] - A[j]] += 1.0 / total;
                else
                    F[A[j] - A[i]] += 1.0 / total;
    dp[0][3 * N] = 1.0;
    for (int it = 0; it < 3; ++it)
        for (int x = 0; x < 6 * N; ++x) {
            if (dp[it][x] > 1e-10) {
                for (int y = 1; y < N; ++y) {
                    if (F[y] > 1e-10) {
                        dp[it + 1][x + (it < 2 ? -1 : +1) * y] += dp[it][x] * F[y];
                    }
                }
            }
        }
    ld ans = 0.0;
    for (int x = 3 * N + 1; x < 6 * N; ++x)
        ans += dp[3][x];
    cout.precision(10);
    cout << fixed << ans << endl;
    return 0;
}