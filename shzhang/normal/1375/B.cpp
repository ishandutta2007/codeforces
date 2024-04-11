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

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int grid[305][305];
int cnt[305][305];

void work(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    bool good = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &(grid[i][j]));
            cnt[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 1 && x <= n && y >= 1 && y <= m) cnt[i][j]++;
            }
            if (grid[i][j] > cnt[i][j]) good = false;
        }
    }
    if (!good) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d ", cnt[i][j]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}