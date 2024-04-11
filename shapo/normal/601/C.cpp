#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int MAXN = 100;
const int MAXM = 1000;

int n, m;
ld dp[2][MAXN * MAXM];
ld sum[MAXN * MAXM];
int used[MAXN];

int
main()
{
    cin >> n >> m;
    int dsum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> used[i];
        --used[i];
        dsum += used[i];
    }
    ld ans = 1.;
    ld div = m - 1;
    if (m != 1) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; ++i) {
            if (used[0] != i) {
                dp[0][i] = 1.;
            }
        }
        for (int i = 1; i < n; ++i) {
            int it = i & 1, pr = it ^ 1;
            memset(dp[it], 0, sizeof(dp[it]));
            memset(sum, 0, sizeof(sum));
            partial_sum(dp[pr], dp[pr] + dsum, sum);
            for (int j = 0; j < dsum; ++j) {
                int l = max(0, j - m + 1), r = j;
                dp[it][j] = sum[r];
                if (l) dp[it][j] -= sum[l - 1];
                if (j >= used[i]) {
                    dp[it][j] -= dp[pr][j - used[i]];
                }
                dp[it][j] /= div;
            }
        }
        ans = 1.;
        for (int j = 0; j < dsum; ++j) {
            ans += dp[(n - 1) & 1][j];
        }
    }
    cout << fixed << setprecision(20) << double(ans) << '\n';
    return 0;
}