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

int a[15];
int pwr3[15];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int mask = 1; mask < pwr3[n]; mask++) {
        int val = 0;
        int cur = mask;
        for (int i = 1; i <= n; i++) {
            if (cur % 3 == 1) {
                val += a[i];
            } else if (cur % 3 == 2) {
                val -= a[i];
            }
            cur /= 3;
        }
        if (val == 0) {
            printf("YES\n"); return;
        }
    }
    printf("NO\n");
}

int main()
{
    pwr3[0] = 1;
    for (int i = 1; i <= 10; i++) pwr3[i] = 3 * pwr3[i-1];
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}