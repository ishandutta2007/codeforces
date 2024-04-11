#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

typedef long long lol;

lol n, m, ans, ax, ay, bx, by, cx, cy, dx, dy;

inline lol query(lol x, lol y) {
    if (x % 2 == 0 || y % 2 == 0) { return x * y / 2; }
    return x * y / 2;
}
inline lol query(lol ux, lol uy, lol vx, lol vy) { return query(vx, vy) + query(ux - 1, uy - 1) - query(ux - 1, vy) - query(vx, uy - 1); }

inline void modify() {
    if (bx < cx) { return; }
    if (dx < ax) { return; }
    if (by < cy) { return; }
    if (dy < ay) { return; }
    ans += query(std::max(ax, cx), std::max(ay, cy), std::min(bx, dx), std::min(by, dy));
}

int main() {
    for (int tn = read(); tn; tn--) {
        n = read(); m = read(); ans = query(n, m);
        ax = read(); ay = read(); bx = read(); by = read();
        cx = read(); cy = read(); dx = read(); dy = read();
        ans = ans - query(ax, ay, bx, by);
        ans = ans - query(cx, cy, dx, dy) + (dx - cx + 1) * (dy - cy + 1);
        modify();
        std::cout << n * m - ans << " " << ans << std::endl;
    }
    return 0;
} //