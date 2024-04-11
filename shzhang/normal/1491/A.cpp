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

int a[100005];
int n, q;

int main()
{
    scanf("%d%d", &n, &q);
    int ones = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (a[i]) ones++;
    }
    for (int i = 1; i <= q; i++) {
        int t, x; scanf("%d%d", &t, &x);
        if (t == 1) {
            if (a[x]) {
                ones--;
            } else {
                ones++;
            }
            a[x] = 1 - a[x];
        } else {
            printf("%d\n", x <= ones ? 1 : 0);
        }
    }
    return 0;
}