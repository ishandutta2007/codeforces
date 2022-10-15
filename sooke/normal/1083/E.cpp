#include <cmath>
#include <cstdio>
#include <algorithm>

inline long long read() {
    char c = getchar(); long long x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

typedef long long lol;

const int maxN = 2000005;
const double eps = 1e-10;

int n, l, r, q[maxN];
long long ans, f[maxN];

struct Square { lol x, y, w; } s[maxN];

bool operator <(Square x, Square y) { return x.y > y.y; }

inline double getX(int u) { return s[u].x; }
inline double getY(int u) { return f[u]; }
inline double getSlope(int u, int v) { return std::abs(getX(v) - getX(u)) < eps ? 1e10 : (getY(v) - getY(u)) / (getX(v) - getX(u)); }

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { s[i].x = read(); s[i].y = read(); s[i].w = read() ;}
    std::sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++) {
        while (l < r && getSlope(q[l], q[l + 1]) >= s[i].y) { l++; }
        f[i] = s[i].x * s[i].y - s[i].w;
        if (l <= r) { f[i] = std::max(f[i], f[q[l]] + (s[i].x - s[q[l]].x) * s[i].y - s[i].w); }
        ans = std::max(ans, f[i]);
        while (l < r && getSlope(q[r - 1], q[r]) <= getSlope(q[r], i)) { r--; } q[++r] = i;
    }
    printf("%I64d\n", ans);
    return 0;
}