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

int n, m;
char a[5005], b[5005];
int f[5005][5005];

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(0, max(f[i-1][j] - 1, f[i][j-1] - 1));
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i-1][j-1] + 2);
            ans = max(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}