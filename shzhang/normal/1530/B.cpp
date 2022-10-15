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

int h, w;
bool grid1[25][25], grid2[25][25], grid3[25][25];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int test(int r, int c, bool a[25][25])
{
    int ret = 0;
    while (!a[r][c]) {
        bool good = true;
        for (int i = 0; i < 8; i++) {
            if (a[r+dx[i]][c+dy[i]]) good = false;
        }
        if (good) {
            a[r][c] = true; ret++;
        }
        if (r == 1 && c < w) {
            c++;
        } else if (c == w && r < h) {
            r++;
        } else if (r == h && c > 1) {
            c--;
        } else {
            r--;
        }
    }
    return ret;
}

void answer(bool a[25][25])
{
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

void work()
{
    scanf("%d%d", &h, &w);
    int a = test(1, 1, grid1);
    int b = test(1, 2, grid2);
    int c = test(2, 1, grid3);
    if (a >= b && a >= c) {
        answer(grid1);
    } else if (b >= a && b >= c) {
        answer(grid2);
    } else {
        answer(grid3);
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            grid1[i][j] = grid2[i][j] = grid3[i][j] = false;
        }
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}