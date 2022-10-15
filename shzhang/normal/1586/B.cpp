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

bool bad[100005];

void work()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) bad[i] = false;
    for (int i = 1; i <= m; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        bad[b] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!bad[i]) {
            for (int j = 1; j <= n; j++) {
                if (j != i) {
                    printf("%d %d\n", i, j);
                }
            }
            break;
        }
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}