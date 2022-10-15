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

int a[500005];
int b[500005];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= 5 * n + 2; i++) a[i] = 0, b[i] = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x); a[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= 5 * n + 1; i++) {
        if (a[i] > 0 || b[i] > 0) {
            ans++;
            int amt = b[i] > 0 ? a[i] : a[i] - 1;
            a[i] -= amt;
            b[i+1] += amt;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}