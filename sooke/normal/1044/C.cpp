#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 300005;

int n, ans;

struct Point { int x, y; } bound[5], p[maxN];

int main() {
    n = read(); bound[1].x = 1e9, bound[2].x = -1e9, bound[3].y = -1e9, bound[4].y = 1e9;
    for (int i = 1; i <= n; i++) {
        p[i].x = read(); p[i].y = read();
        if (bound[1].x > p[i].x) { bound[1] = p[i]; }
        if (bound[2].x < p[i].x) { bound[2] = p[i]; }
        if (bound[3].y < p[i].y) { bound[3] = p[i]; }
        if (bound[4].y > p[i].y) { bound[4] = p[i]; }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= n; k++) { ans = std::max(ans, (std::max(bound[i].x, std::max(bound[j].x, p[k].x)) - std::min(bound[i].x, std::min(bound[j].x, p[k].x)) + std::max(bound[i].y, std::max(bound[j].y, p[k].y)) - std::min(bound[i].y, std::min(bound[j].y, p[k].y))) * 2); }
        }
    }
    printf("%d ", ans);
    for (int i = 4; i <= n; i++) { printf("%d ", (bound[2].x + bound[3].y - bound[1].x - bound[4].y) * 2); }
    return 0;
} //