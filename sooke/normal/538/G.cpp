#include <bits/stdc++.h>
 
inline long long read() {
    char c, _c; long long x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}
 
const int N = 2e6 + 5;
 
int n, m;
char ans[2][N];
 
struct Point {
    long long x, k, t;
} p[2][N];
 
bool operator <(const Point &u, const Point &v) {
    return u.t < v.t;
}
 
int main() {
    n = read(); m = read(); n++;
    for (int i = 1; i < n; i++) {
        long long t = read(), x = read(), y = read();
        if ((x + y + t) % 2 != 0) { printf("NO\n"); return 0; }
        p[0][i] = (Point) {x + y, t / m, t % m};
        p[1][i] = (Point) {x - y, t / m, t % m};
    }
    p[0][n] = (Point) {0, -1, m};
    p[1][n] = (Point) {0, -1, m};
    n++;
    for (int o = 0; o <= 1; o++) {
        std::sort(p[o], p[o] + n);
        long long l = -m, r = m;
        for (int i = 1; i < n; i++) {
            long long dx = p[o][i].x - p[o][i - 1].x;
            long long dk = p[o][i].k - p[o][i - 1].k;
            long long dt = p[o][i].t - p[o][i - 1].t;
            if (dk == 0) {
                if (std::abs(dx) > dt) { printf("NO\n"); return 0; }
                continue;
            }
            if (dk < 0) { dk = -dk; dx = -dx; }
            l = std::max(l, (long long) ceil(1.0L * (dx - dt) / dk));
            r = std::min(r, (long long) floor(1.0L * (dx + dt) / dk));
        }
        long long x = r + 1;
        for (; l <= r; l++) {
            if ((l + m) % 2 == 0) { x = l; break; }
        }
        if (x > r) { printf("NO\n"); return 0; }
        for (int i = 1; i < n; i++) {
            long long d = (p[o][i - 1].x - p[o][i - 1].k * x) - (p[o][i].x - p[o][i].k * x);
            for (int t = p[o][i - 1].t; t < p[o][i].t; t++) {
                if (d < 0) {
                    ans[o][t] = '+'; d++;
                } else {
                    ans[o][t] = '-'; d--;
                }
            }
            if (d != 0) { printf("NO\n"); return 0; }
        }
    }
    for (int i = 0; i < m; i++) {
        if (ans[0][i] == '+' && ans[1][i] == '-') { putchar('U'); }
        if (ans[0][i] == '-' && ans[1][i] == '-') { putchar('L'); }
        if (ans[0][i] == '-' && ans[1][i] == '+') { putchar('D'); }
        if (ans[0][i] == '+' && ans[1][i] == '+') { putchar('R'); }
    }
    return 0;
} //