#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, k, ord[N];
long long ans = -1e18, w[N];
std::pair<long long, long long> a[N], b[N];

struct SegmentTree {
    long long f[N << 2], g[N << 2];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = std::max(f[ls], f[rs]);
    }
    inline void pushTag(int u, long long x) {
        f[u] += x; g[u] += x;
    }
    inline void pushDown(int u) {
        if (g[u] != 0) {
            int ls = u << 1, rs = ls | 1;
            pushTag(ls, g[u]); pushTag(rs, g[u]);
            g[u] = 0;
        }
    }

    inline void modify(int u, int l, int r, int pl, int pr, long long x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { pushTag(u, x); return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            modify(ls, l, mid, pl, pr, x);
        } else if (pl >= mid) {
            modify(rs, mid, r, pl, pr, x);
        } else {
            modify(ls, l, mid, pl, mid, x);
            modify(rs, mid, r, mid, pr, x);
        }
        pushUp(u);
    }
} smt;

struct Person {
    int x, y, z;
} s[N];

bool compare(Person i, Person j) {
    return i.y < j.y;
}

void modify(int i, long long x) {
    smt.modify(1, 0, 1e6, i - 1, 1e6, x);
}
long long query() {
    return smt.f[1];
}

int main() {
    n = read(); m = read(); k = read();
    for (int i = 0; i <= 1e6; i++) { w[i] = 2e9; }
    for (int i = 0; i < n; i++) {
        a[i].first = read() - 1; a[i].second = read();
        w[a[i].first] = std::min(w[a[i].first], a[i].second);
    }
    w[0] = 0;
    for (int i = 1; i <= 1e6; i++) {
        modify(i, w[i - 1] - w[i]);
    }
    for (int i = 0; i < m; i++) {
        b[i].first = read() - 1; b[i].second = read();
    }
    std::sort(b, b + m);
    for (int i = 0; i < k; i++) {
        s[i].x = read(); s[i].y = read(); s[i].z = read();
    }
    std::sort(s, s + k, compare);
    for (int i = 0, j = 0; i < m; i++) {
        for (; j < k && s[j].y <= b[i].first; j++) {
            modify(s[j].x, s[j].z);
        }
        ans = std::max(ans, query() - b[i].second);
    }
    printf("%lld\n", ans);
    return 0;
}