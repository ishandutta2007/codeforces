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

int n, x;
int a[1005];

void work()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    bool all_equal = true; bool has_equal = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] != x) {
            all_equal = false;
        } else {
            has_equal = true;
        }
    }
    if (all_equal) {
        printf("0\n"); return;
    }
    if (has_equal) {
        printf("1\n"); return;
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) tot += a[i];
    if (tot == x * n) {
        printf("1\n"); return;
    }
    printf("2\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}