#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5100;

typedef double ld;

int n, T;
int pr[MAXN], t[MAXN];
ld rest[MAXN];

ld dp[MAXN][MAXN];

ld pw[MAXN];

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> T;
    for (int i = 1; i <= n; ++i) {
        cin >> pr[i] >> t[i];
        ld mult = (100. - pr[i]) / 100.;
        rest[i] = 1.;
        for (int k = 1; k < t[i]; ++k) {
            rest[i] = (rest[i] * mult + .1) - .1;
        }
    }
    dp[0][0] = 1.;
    for (int i = 1; i <= n; ++i) {
        if (t[i] == 1) {
            for (int j = 1; j <= T; ++j) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        } else {
            ld p = pr[i] / 100., q = 1 - p;
            ld cur_val = 0.;
            ld last_prob = p;
            {
                ld tmp = q;
                int pw = t[i] - 2;
                while (pw) {
                    if (pw & 1) {
                        last_prob = (last_prob * tmp + .1) - .1;
                    }
                    pw /= 2;
                    tmp *= tmp;
                }
            }
            for (int j = 1, r = 0; j <= T; ++j) {
                if (j > r + (t[i] - 1)) {
                    cur_val -= dp[i - 1][r] * last_prob;
                    ++r;
                }
                cur_val = (cur_val * q + p * dp[i - 1][j - 1] + .1) - .1;
                dp[i][j] = cur_val;
                if (j >= t[i]) {
                    dp[i][j] += rest[i] * dp[i - 1][j - t[i]];
                }
            }
        }
    }
    ld res = 0.;
    for (int i = 1; i < n; ++i) {
        pw[1] = 1;
        ld q = (100. - pr[i + 1]) / 100.;
        for (int j = 2; j <= t[i + 1]; ++j) {
            pw[j] = (pw[j - 1] * q + .1) - .1;
        }
        for (int j = t[i + 1] + 1; j <= T; ++j) {
            pw[j] = 0.;
        }
        for (int j = 1; j <= T; ++j) {
            res += i * dp[i][j] * pw[T + 1 - j];
        }
    }
    // all problems solved
    for (int j = 1; j <= T; ++j) {
        res += n * dp[n][j];
    }
    cout << fixed << setprecision(10);
    cout << res << '\n';
    return 0;
}