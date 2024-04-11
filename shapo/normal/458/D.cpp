#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef double ld;

const int MAXN = 310;
const int MAXM = 100500;

ld binom[MAXN][MAXN];
ld multCoeff[MAXM];

void
calcBinom()
{
    binom[0][0] = 1.;
    for (int i = 1; i < MAXN; ++i) {
        binom[i][0] = 1.;
        for (int j = 1; j <= i; ++j) {
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
        }
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
    calcBinom();
    int n, m, k;
    cin >> n >> m >> k;
    multCoeff[0] = 1.;
    for (int i = 1; i <= k; ++i) {
        multCoeff[i] = multCoeff[i - 1] * (k - i + 1.) / (m - i + 1.);
    }
    ld ans = 0.;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            int filled = n * (i + j) - i * j;
            if (filled <= k) {
                ans += binom[n][i] * binom[n][j] * multCoeff[filled];
            }
        }
    }
    if (ans > 1e99) {
        cout << "1e99\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}