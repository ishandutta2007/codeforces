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

int a[1005];

int main()
{
    int t;
    scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        bool found = false;
        for (int i = 2; i < n; i++) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) {
                printf("YES\n%d %d %d\n", i-1, i, i+1); found = true; break;
            }
        }
        if (!found) {
            printf("NO\n");
        }
    }
    return 0;
}