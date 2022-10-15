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

int p[505];
int ans[505][505];
int x[505];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    for (int i = 1; i <= n; i++) {
        int cur = i;// int remaining = p[i];
        for (int j = 1; j <= p[i]; j++) {
            x[cur]++; ans[cur][x[cur]] = p[i];
            if (cur == i) {
                if (x[cur] == cur) cur++;
            } else {
                if (ans[cur-1][x[cur]] == p[i]) cur++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}