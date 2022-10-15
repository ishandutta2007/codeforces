#include <bits/stdc++.h>

const int inf = 1e9;

int T, ans, dir[4];

struct Point {
    int x, y;
} a[4], b[4], sol[4];

bool operator <(const Point &u, const Point &v) {
    return u.x == v.x ? u.y < v.y : u.x < v.x;
}

void update(int xl, int xr, int yl, int yr) {
    if (xl > xr) { std::swap(xl, xr); }
    if (yl > yr) { std::swap(yl, yr); }
    if (xr - xl != yr - yl) { return; }
    b[0] = (Point) {xl, yl}; b[1] = (Point) {xl, yr};
    b[2] = (Point) {xr, yl}; b[3] = (Point) {xr, yr};
    do {
        int res = 0;
        for (int i = 0; i < 4; i++) {
            if (dir[i] == 0) {
                if (a[i].x == b[i].x) {
                    res = std::max(res, std::abs(a[i].y - b[i].y));
                } else {
                    res = inf;
                }
            } else {
                if (a[i].y == b[i].y) {
                    res = std::max(res, std::abs(a[i].x - b[i].x));
                } else {
                    res = inf;
                }
            }
        }
        if (ans > res) {
            ans = res;
            for (int i = 0; i < 4; i++) {
                sol[i] = b[i];
            }
        }
    } while (std::next_permutation(b, b + 4));
}

int main() {
    for (scanf("%d", &T); T; T--) {
        ans = inf;
        for (int i = 0; i < 4; i++) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        for (int s = 0; s < 16; s++) {
            int xl, xr, yl, yr, res, pos;
            bool gg = false;
            xl = xr = yl = yr = res = inf;
            for (int i = 0; i < 4; i++) {
                dir[i] = s >> i & 1;
                if (dir[i] == 0) {
                    if (xl == inf || xl == a[i].x) {
                        xl = a[i].x;
                    } else if (xr == inf || xr == a[i].x) {
                        xr = a[i].x;
                    } else {
                        gg = true;
                    }
                } else {
                    if (yl == inf || yl == a[i].y) {
                        yl = a[i].y;
                    } else if (yr == inf || yr == a[i].y) {
                        yr = a[i].y;
                    } else {
                        gg = true;
                    }
                }
            }
            if (gg) { continue; }
            if (xr != inf && yr != inf) {
                update(xl, xr, yl, yr);
            } else if (xr != inf && yl != inf) {
                update(xl, xr, yl, yl + std::abs(xl - xr));
                update(xl, xr, yl, yl - std::abs(xl - xr));
            } else if (xl != inf && yr != inf) {
                update(xl, xl + std::abs(yl - yr), yl, yr);
                update(xl, xl - std::abs(yl - yr), yl, yr);
            } else if (xr != inf) {
                for (int l = 0, r = inf, mid; l <= r; ) {
                    mid = l + r >> 1;
                    int sl = -inf, sr = inf;
                    for (int o = 0; o < 2; o++) {
                        int x = o == 0 ? xl : xr;
                        for (int i = 0; i < 4; i++) {
                            for (int j = 0; j < i; j++) {
                                if (x == a[i].x && x == a[j].x) {
                                    sl = std::max(sl, std::min(a[i].y, a[j].y) - mid);
                                    sr = std::min(sr, std::min(a[i].y, a[j].y) + mid);
                                    sl = std::max(sl, std::max(a[i].y, a[j].y) - mid - std::abs(xl - xr));
                                    sr = std::min(sr, std::max(a[i].y, a[j].y) + mid - std::abs(xl - xr));
                                }
                            }
                        }
                    }
                    if (sl <= sr) {
                        r = mid - 1; res = mid; pos = sl;
                    } else {
                        l = mid + 1;
                    }
                }
                if (res == inf) { continue; }
                update(xl, xr, pos, pos + std::abs(xl - xr));
            } else if (yr != inf) {
                for (int l = 0, r = inf, mid; l <= r; ) {
                    mid = l + r >> 1;
                    int sl = -inf, sr = inf;
                    for (int o = 0; o < 2; o++) {
                        int y = o == 0 ? yl : yr;
                        for (int i = 0; i < 4; i++) {
                            for (int j = 0; j < i; j++) {
                                if (y == a[i].y && y == a[j].y) {
                                    sl = std::max(sl, std::min(a[i].x, a[j].x) - mid);
                                    sr = std::min(sr, std::min(a[i].x, a[j].x) + mid);
                                    sl = std::max(sl, std::max(a[i].x, a[j].x) - mid - std::abs(yl - yr));
                                    sr = std::min(sr, std::max(a[i].x, a[j].x) + mid - std::abs(yl - yr));
                                }
                            }
                        }
                    }
                    if (sl <= sr) {
                        r = mid - 1; res = mid; pos = sl;
                    } else {
                        l = mid + 1;
                    }
                }
                if (res == inf) { continue; }
                update(pos, pos + std::abs(yl - yr), yl, yr);
            }
        }
        if (ans == inf) { printf("-1\n"); continue; }
        printf("%d\n", ans);
        for (int i = 0; i < 4; i++) {
            printf("%d %d\n", sol[i].x, sol[i].y);
        }
    }
    return 0;
}