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
int B[500005];
int N[500005];
char tmp[500005];

int ansx, ansy;

bool check(int d)
{
    int x_l = -1000000000, x_r = 1000000000;
    int y_l = -1000000000, y_r = 1000000000;
    int xy_l = -1000000000, xy_r = 1000000000;
    for (int i = 1; i <= n; i++) {
        x_l = max(x_l, B[i] - d);
        x_r = min(x_r, B[i] + d);
        y_l = max(y_l, N[i] - d);
        y_r = min(y_r, N[i] + d);
        xy_l = max(xy_l, B[i] - N[i] - d);
        xy_r = min(xy_r, B[i] - N[i] + d);
    }
    x_l = max(x_l, 0);
    y_l = max(y_l, 0);
    if (x_l > x_r || y_l > y_r || xy_l > xy_r) return false;
    //if (x_l - y_r > xy_r || x_r - y_l < xy_l) return false;
    if (x_r == 0 && y_r == 0) {
        return false;
    } else {
        ansx = x_r; ansy = y_r;
        int cur_xy = ansx - ansy;
        if (xy_l <= cur_xy && cur_xy <= xy_r) {
             return true;
        } else if (cur_xy <= xy_l) {
            ansy -= xy_l - cur_xy;
            return (ansx > 0 || ansy > 0) && x_l <= ansx && ansx <= x_r &&
                y_l <= ansy && ansy <= y_r && xy_l <= ansx-ansy && ansx-ansy <= xy_r;
        } else {
            ansx -= cur_xy - xy_r;
            return (ansx > 0 || ansy > 0) && x_l <= ansx && ansx <= x_r &&
                y_l <= ansy && ansy <= y_r && xy_l <= ansx-ansy && ansx-ansy <= xy_r;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", tmp + 1);
        for (int j = 1; tmp[j]; j++) {
            if (tmp[j] == 'B') B[i]++;
            else N[i]++;
        }
    }

    int l = 0;
    int r = 10000000;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    check(l);
    printf("%d\n", l);
    for (int i = 1; i <= ansx; i++) printf("B");
    for (int i = 1; i <= ansy; i++) printf("N");
    return 0;
}