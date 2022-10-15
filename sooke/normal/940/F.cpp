#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int maxN = 200005;

int n, m, qn, mn, len, now, num, a[maxN], table[maxN << 1], pos[maxN], ans[maxN], mdf[maxN], pre[maxN], nxt[maxN], cnt[maxN << 1], cnt2[maxN << 1];

struct Query { int id, l, r, t; } q[maxN];
bool operator <(const Query &x, const Query &y) {
    if (pos[x.l] == pos[y.l]) {
        return pos[x.r] == pos[y.r] ? ((pos[x.r] & 1) ? x.t < y.t : x.t > y.t) : ((pos[x.l] & 1) ? x.r < y.r : x.r > y.r); 
    } else { return x.l < y.l; }
}

inline void remove(int x) {
    cnt2[x]--;
    if (cnt2[x] <= 0) { now = std::min(now, x); }
}
inline void insert(int x) {
    cnt2[x]++;
    while (cnt2[now] > 0) { now++; }
}
inline void ins(int x) { remove(cnt[x]++); insert(cnt[x]); }
inline void del(int x) { remove(cnt[x]--); insert(cnt[x]); }

int main() {
    n = read(); m = read(); len = pow(n, 0.667);
    for (int i = 1; i <= n; i++) { table[++num] = a[i] = read(); pos[i] = (i - 1) / len + 1; }
    for (int i = 1; i <= m; i++) {
        int opt = read();
        if (opt == 1) { qn++; q[qn].id = qn; q[qn].l = read(); q[qn].r = read(); q[qn].t = mn; }
        else { mn++; mdf[mn] = read(); pre[mn] = a[mdf[mn]]; table[++num] = a[mdf[mn]] = nxt[mn] = read(); }
    }
    std::sort(q + 1, q + qn + 1); cnt2[0] = 1e9;
    for (int i = mn; i; i--) { a[mdf[i]] = pre[i]; }
    std::sort(table + 1, table + num + 1); num = std::unique(table + 1, table + num + 1) - table - 1;
    for (int i = 1; i <= n; i++) { a[i] = std::lower_bound(table + 1, table + num + 1, a[i]) - table; }
    for (int i = 1; i <= mn; i++) { pre[i] = std::lower_bound(table + 1, table + num + 1, pre[i]) - table; nxt[i] = std::lower_bound(table + 1, table + num + 1, nxt[i]) - table; }
    for (int i = 1, l = 1, r = 0, t = 0; i <= qn; i++) {
        while (r < q[i].r) { ins(a[++r]); }
        while (l > q[i].l) { ins(a[--l]); }
        while (q[i].r < r) { del(a[r--]); }
        while (q[i].l > l) { del(a[l++]); }
        while (t < q[i].t) {
            t++;
            if (l <= mdf[t] && mdf[t] <= r) { del(a[mdf[t]]); ins(nxt[t]); }
            a[mdf[t]] = nxt[t];
        }
        while (t > q[i].t) {
            if (l <= mdf[t] && mdf[t] <= r) { del(a[mdf[t]]); ins(pre[t]); }
            a[mdf[t]] = pre[t];
            t--; 
        }
        ans[q[i].id] = now;
    }
    for (int i = 1; i <= qn; i++) { printf("%d\n", ans[i]); }
    return 0;
} //