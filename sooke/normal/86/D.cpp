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

typedef long long lol;

const int maxN = 1000005;

int n, m, len, a[maxN], pos[maxN], cnt[maxN];
lol now, ans[maxN];

struct Query { int id, l, r; } q[maxN];
bool cmp(Query x, Query y) { return pos[x.l] == pos[y.l] ? ((pos[x.l] & 1) ? x.r < y.r : x.r > y.r) : x.l < y.l; }

inline void modify(int x, int f) { now -= 1ll * cnt[x] * cnt[x] * x; cnt[x] += f; now += 1ll * cnt[x] * cnt[x] * x; }

int main() {
    n = read(); m = read(); len = sqrt(n);
    for (int i = 1; i <= n; i++) { a[i] = read(); pos[i] = (i - 1) / len + 1; }
    for (int i = 1; i <= m; i++) { q[i].id = i; q[i].l = read(); q[i].r = read(); }
    std::sort(q + 1, q + m + 1, cmp);
    for (int i = 1, l = 1, r = 0; i <= m; i++) {
        while (q[i].l < l) { modify(a[--l], 1); }
        while (r < q[i].r) { modify(a[++r], 1); }
        while (l < q[i].l) { modify(a[l++], -1); }
        while (q[i].r < r) { modify(a[r--], -1); }
        ans[q[i].id] = now;
    }
    for (int i = 1; i <= m; i++) { printf("%I64d\n", ans[i]); }
    return 0;
}