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
int a[200005];
int T;

int main()
{
    scanf("%d", &T);
    for (int d = 1; d <= T; d++) {
        scanf("%d", &n);
        bool eq = true;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            if (i > 1 && a[i] != a[i-1]) eq = false;
        }
        if (eq) {
            printf("%d\n", n);
        } else {
            printf("1\n");
        }
    }
    return 0;
}