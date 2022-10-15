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
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int N = 200005;

int n, q;
char str[N];

struct SegmentTree {
    int f[N << 2], g[N << 2], h[N << 2], sum[N << 2], max[N << 2], min[N << 2];

    inline void pushUp(int u) {
        int l = u << 1, r = l | 1;
        sum[u] = sum[l] + sum[r];
        max[u] = std::max(max[l], sum[l] + max[r]);
        min[u] = std::min(min[l], sum[l] + min[r]);
        f[u] = std::max(std::max(max[l] - sum[l] + h[r], sum[l] + g[l] + max[r]), std::max(f[l], f[r]));
        g[u] = std::max(std::max(g[l], g[r] - sum[l]), max[l] - (sum[l] + min[r]) * 2);
        h[u] = std::max(std::max(h[l], h[r] - sum[l]), sum[l] - min[l] * 2 + max[r]);
    }
    void build(int u, int l, int r) {
        if (l == r) {
            max[u] = min[u] = sum[u] = str[l] == '(' ? 1 : -1;
            g[u] = h[u] = str[l] == '(' ? -1 : 1;
            return;
        }
        int mid = l + r >> 1; build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r); pushUp(u);
    }
    void modify(int u, int l, int r, int pos) {
        if (l == r) {
            max[u] = min[u] = sum[u] = str[l] == '(' ? 1 : -1;
            g[u] = h[u] = str[l] == '(' ? -1 : 1;
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid) { modify(u << 1, l, mid, pos); } else { modify(u << 1 | 1, mid + 1, r, pos); }
        pushUp(u);
    }
} smt;

int main() {
    n = read(); q = read(); scanf("%s", str + 1); smt.build(1, 0, n * 2 - 2);
    printf("%d\n", smt.f[1]);
    for (int l, r; q; q--) {
        l = read(); r = read(); std::swap(str[l], str[r]);
        smt.modify(1, 0, n * 2 - 2, l); smt.modify(1, 0, n * 2 - 2, r);
        printf("%d\n", smt.f[1]);
    }
    return 0;
} // sooke