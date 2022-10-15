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

int grid[55][55];

void work(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) scanf("%d", &(grid[i][j]));
    }
    int rows = 0; int cols = 0;
    for (int i = 1; i <= n; i++) {
        bool good = true;
        for (int j = 1; j <= m; j++) {
            if (grid[i][j]) good = false;
        }
        if (good) rows++;
    }
    for (int i = 1; i <= m; i++) {
        bool good = true;
        for (int j = 1; j <= n; j++) {
            if (grid[j][i]) good = false;
        }
        if (good) cols++;
    }
    printf("%s\n", min(rows, cols) % 2 ? "Ashish" : "Vivek");
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}