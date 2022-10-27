#include <iostream>
using namespace std;
const int N = 200000 + 10;
int n, sx, sy, x[N], y[N];

int main() {
    scanf("%d%d%d", &n, &sx, &sy);
    int lx = 0, rx = 0, ly = 0, ry = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &x[i], &y[i]);
        if (x[i] <= sx - 1) lx ++;
        if (x[i] >= sx + 1) rx ++;
        if (y[i] <= sy - 1) ly ++;
        if (y[i] >= sy + 1) ry ++;
    }
    int ans = 0, cx, cy;
    if (lx >= ans) {
        ans = lx, cx = sx - 1, cy = sy;
    }
    if (rx >= ans) {
        ans = rx, cx = sx + 1, cy = sy;
    }
    if (ly >= ans) {
        ans = ly, cx = sx, cy = sy - 1;
    } 
    if (ry >= ans) {
        ans = ry, cx = sx, cy = sy + 1;
    }
    printf("%d\n", ans);
    printf("%d %d\n", cx, cy);
}