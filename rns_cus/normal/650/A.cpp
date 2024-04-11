#include <bits/stdc++.h>

using namespace std;

#define N 200005

struct Point {
    int x, y;
    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
} p[N];

bool cmp(Point a, Point b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }

main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    sort(p + 1, p + n + 1);
    __int64 rlt = 0;
    for (int i = 1, j; i <= n; ) {
        for (j = i + 1; j <= n; j ++) {
            if (p[j].x != p[i].x) break;
        }
        int cnt = j - i;
        rlt += 1LL * cnt * (cnt - 1) / 2;
        i = j;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1, j; i <= n; ) {
        for (j = i + 1; j <= n; j ++) {
            if (p[j].y != p[i].y) break;
        }
        int cnt = j - i;
        rlt += 1LL * cnt * (cnt - 1) / 2;
        i = j;
    }
    for (int i = 1, j; i <= n; ) {
        for (j = i + 1; j <= n; j ++) {
            if (p[i].x != p[j].x || p[i].y != p[j].y) break;
        }
        int cnt = j - i;
        rlt -= 1LL * cnt * (cnt - 1) / 2;
        i = j;
    }
    printf("%I64d\n", rlt);
}