#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

struct Triple {
    int i, j, k;
};

int n, K;
int f[405][405][55];
int a[405], s[405];

int fval(Triple trip)
{
    return f[trip.i][trip.j][trip.k];
}

int sumv(Triple trip)
{
    return s[trip.i] - s[trip.j-1];
}

int absolute(int A)
{
    if (A < 0) return -A;
    return A;
}

Triple hintv[405][405], lintv[405][405];

int main()
{
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); s[i] = s[i-1] + a[i];
    }
    int ans = -1000000000;
    f[0][0][0] = -1000000000;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= min(i, K); k++) {
            hintv[i][k] = hintv[i-1][k];
            lintv[i][k] = lintv[i-1][k];
        }
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= min(i, K); k++) {
                Triple cur_triple; cur_triple.i = i;
                cur_triple.j = j; cur_triple.k = k;
                if (k > 1) {
                    f[i][j][k] = max(fval(hintv[j-1][k-1])
                        + absolute(sumv(hintv[j-1][k-1]) - s[i] + s[j-1]),
                                    fval(lintv[j-1][k-1])
                        + absolute(sumv(lintv[j-1][k-1]) - s[i] + s[j-1]));
                    //debug("%d %d f[%d][%d][%d] = %d\n", fval(hintv[j-1][k-1]), fval(lintv[j-1][k-1]), i, j, k, f[i][j][k]);
                }
                if (fval(hintv[i][k]) + sumv(hintv[i][k]) <
                    fval(cur_triple) + sumv(cur_triple)) hintv[i][k] = cur_triple;
                if (fval(lintv[i][k]) - sumv(lintv[i][k]) <
                    fval(cur_triple) - sumv(cur_triple)) lintv[i][k] = cur_triple;
            }
            if (i >= K) {
                for (int x = 1; x <= i; x++) {
                    ans = max(ans, f[i][x][K]);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}