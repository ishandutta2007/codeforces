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

int f[2][105][10005];
int n;
int a[105]; int b[105];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", a + i, b + i);
    }
    int a_sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= 10000; k++) {
                f[i][j][k] = -1000000000;
            }
        }
    }
    f[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i + 1; j++) {
            for (int k = 0; k <= a_sum + a[i+1]; k++) {
                f[(i+1)%2][j][k] = -1000000000;
            }
        }
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= a_sum; k++) {
                f[(i+1)%2][j][k] = max(f[(i+1)%2][j][k], f[i%2][j][k]);
                f[(i+1)%2][j+1][k+a[i+1]] = max(f[(i+1)%2][j+1][k+a[i+1]],
                    f[i%2][j][k] + b[i+1]);
            }
        }
        a_sum += a[i+1];
    }
    double tot = 0;
    for (int i = 1; i <= n; i++) tot += (double)b[i];
    for (int i = 1; i <= n; i++) {
        double ans = 0;
        for (int j = 0; j <= 10000; j++) {
            ans = max(ans, min((double)j, tot / 2.0 + (double)f[n%2][i][j] / 2.0));
        }
        printf("%.9f ", ans);
    }
    return 0;
}