#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const double eps = 1e-8, inf = 1e18;
const int N = 1e5 + 5, S = 320;

int n, len, num, a[N], ord[N], bln[N], bl[N], br[N];
int s[S], t[S], que[S][N];
long long ans, f[N], taga[S], tagb[S];

bool compare(int i, int j) {
    return a[i] < a[j];
}

inline double getSlope(int i, int j) {
    if (a[j] - a[i] < eps) { return f[j] - f[i] > 0 ? eps : -eps; }
    return 1.0 * (f[j] - f[i]) / (a[j] - a[i]);
}
inline long long getValue(int i) {
    return f[i] + taga[bln[i]] * a[i] + tagb[bln[i]];
}

void build(int p) {
    for (int i = bl[p]; i <= br[p]; i++) { f[i] = getValue(i); }
    taga[p] = tagb[p] = t[p] = 0; s[p] = 1;
    for (int i = bl[p]; i <= br[p]; i++) {
        for (; s[p] < t[p] && getSlope(que[p][t[p] - 1], que[p][t[p]]) - eps <= getSlope(que[p][t[p]], ord[i]); t[p]--);
        que[p][++t[p]] = ord[i];
    }
}
void update(int p) {
    for (; s[p] < t[p] && getValue(que[p][s[p]]) <= getValue(que[p][s[p] + 1]); s[p]++);
}

int main() {
    n = read(); len = sqrt(n);
    for (int i = 0; i < n; i++) {
        a[i] = read(); ord[i] = i;
        f[i] = a[i];
    }
    memset(bl, -1, (n + 1) * 4);
    for (int i = 0; i < n; i++) {
        bln[i] = i / len;
        if (bl[bln[i]] < 0) { bl[bln[i]] = i; }
        br[bln[i]] = i;
    }
    num = bln[n - 1] + 1;
    for (int p = 0; p < num; p++) {
        std::sort(ord + bl[p], ord + br[p] + 1, compare);
        build(p);
    }
    for (int _ = 0, i; _ < n; _++) {
        long long d = -inf;
        for (int p = 0; p < num; p++) {
            update(p);
            if (d < getValue(que[p][s[p]])) {
                d = getValue(que[p][s[p]]); i = que[p][s[p]];
            }
        }
        if (d <= 0) { break; }
        ans += d; f[i] += -inf;
        for (int p = 0; p < bln[i]; p++) { tagb[p] += a[i]; }
        for (int j = bl[bln[i]]; j < i; j++) { f[j] += a[i]; }
        for (int p = num - 1; p > bln[i]; p--) { taga[p]++; }
        for (int j = br[bln[i]]; j > i; j--) { f[j] += a[j]; }
        build(bln[i]);
    }
    printf("%lld\n", ans);
    return 0;
}