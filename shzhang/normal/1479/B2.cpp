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

int n;
int a[100005];

int f[100005];

int minv = 0;
int addval = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) f[i] = 100000000;
    for (int i = 1; i <= n; i++) {
        int special = min(f[a[i]] + addval, minv + 1);
        if (a[i] != a[i-1]) {
            addval++; minv++;
        }
        int tval = f[a[i-1]] + addval;
        tval = min(tval, special);
        minv = min(minv, tval);
        f[a[i-1]] = tval - addval;
    }
    int ans = 100000000;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, f[i] + addval);
    }
    printf("%d", ans);
    return 0;
}