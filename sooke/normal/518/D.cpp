#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

const int maxN = 2005;

int n, m;
double ans, p, f[maxN][maxN];

int main() {
    std::cin >> n >> p >> m;
    f[0][n] = 1.0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < n; j++) { f[i][j] = f[i - 1][j] * (1.0 - p) + f[i - 1][j + 1] * p; }
        f[i][0] = f[i - 1][0] + f[i - 1][1] * p, f[i][n] = f[i - 1][n] * (1.0 - p);
    }
    for (int i = 0; i <= n; i++) { ans += f[m][i] * (n - i); }
    printf("%.6lf\n", ans);
    return 0;
}