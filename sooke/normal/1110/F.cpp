#include <cstdio>
#include <algorithm>
#include <vector>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int maxN = 500005;

int n, m, fa[maxN], val[maxN], siz[maxN];
long long ans[maxN], dis[maxN];
std::vector<int> id[maxN], ql[maxN], qr[maxN];
bool isLeaf[maxN];

struct SegmentTree {
    long long f[maxN << 2], tag[maxN << 2];

    inline void pushUp(int u) { f[u] = std::min(f[u << 1], f[u << 1 | 1]); }
    inline void pushTag(int u, long long x) { f[u] += x; tag[u] += x; }
    inline void pushDown(int u) { if (tag[u]) { pushTag(u << 1, tag[u]); pushTag(u << 1 | 1, tag[u]); tag[u] = 0; } }
    void build(int u, int l, int r) {
        if (l == r) { f[u] = isLeaf[l] ? dis[l] : 1e18; return; }
        int mid = l + r >> 1; build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
        pushUp(u);
    }
    void modify(int u, int l, int r, int pl, int pr, int x) {
        if (l == pl && r == pr) { pushTag(u, x); return; }
        int mid = l + r >> 1; pushDown(u);
        if (pr <= mid) { modify(u << 1, l, mid, pl, pr, x); }
        else if (pl > mid) { modify(u << 1 | 1, mid + 1, r, pl, pr, x); }
        else { modify(u << 1, l, mid, pl, mid, x); modify(u << 1 | 1, mid + 1, r, mid + 1, pr, x); }
        pushUp(u);
    }
    void query(int u, int l, int r, int pl, int pr, long long &res) {
        if (l == pl && r == pr) { res = std::min(res, f[u]); return; }
        int mid = l + r >> 1; pushDown(u);
        if (pr <= mid) { query(u << 1, l, mid, pl, pr, res); }
        else if (pl > mid) { query(u << 1 | 1, mid + 1, r, pl, pr, res); }
        else { query(u << 1, l, mid, pl, mid, res); query(u << 1 | 1, mid + 1, r, mid + 1, pr, res); }
        pushUp(u);
    }
} tr;

inline void modify(int u, int sgn) { tr.modify(1, 1, n, 1, n, sgn * val[u]); tr.modify(1, 1, n, u, u + siz[u] - 1, -sgn * val[u] << 1); }

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { siz[i] = 1; isLeaf[i] = true; }
    for (int i = 2; i <= n; i++) {
        fa[i] = read(); val[i] = read();
        dis[i] = dis[fa[i]] + val[i]; isLeaf[fa[i]] = false;
    }
    for (int i = n; i >= 2; i--) { siz[fa[i]] += siz[i]; }
    tr.build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int u = read(), l = read(), r = read();
        id[u].push_back(i); ql[u].push_back(l); qr[u].push_back(r);
        ans[i] = 1e18;
    }
    for (int i = 1, u; i <= n; i++, u = i - 1) {
        if (i > 1) {
            while (u != fa[i]) { modify(u, -1); u = fa[u]; }
            modify(i, 1);
        }
        for (int j = 0; j < (int) id[i].size(); j++) { tr.query(1, 1, n, ql[i][j], qr[i][j], ans[id[i][j]]); }
    }
    for (int i = 1; i <= m; i++) { printf("%I64d\n", ans[i]); }
    return 0;
} // Sooke