#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 1e6 + 5, maxE = 1e7 + 5;

struct List {
    int len, fst[maxN], nxt[maxE], v[maxE];
    
    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int vv) { v[len] = vv, nxt[len] = fst[u], fst[u] = len++; }
    inline void connect(int u, int vv) { insert(u, vv), insert(vv, u); }
} ls;

int n, m, num, cnt, ans[maxN], ord[maxN], pre[maxN], nxt[maxN];
bool del[maxN];
std::queue<int> q;

inline void insert(int u, int l, int r) { nxt[l] = u, pre[u] = l, nxt[u] = r, pre[r] = u; }
inline void split(int x, int y, int l, int r) { pre[x] = l, nxt[l] = x, nxt[y] = r, pre[r] = y; }
inline void remove(int u) { nxt[pre[u]] = nxt[u], pre[nxt[u]] = pre[u]; }

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) { ls.connect(read(), read()); }
    for (int i = 1; i <= n; i++) { ord[i] = i; }
    std::random_shuffle(ord + 1, ord + n + 1);
    nxt[0] = n + 1, pre[n + 1] = 0;
    nxt[n + 2] = n + 3, pre[n + 3] = n + 2;
    for (int i = 1; i <= n; i++) { insert(ord[i], ord[i - 1], n + 1); }
    q.push(ord[1]); remove(ord[1]); del[ord[1]] = true;
    for (int i = 1, u; i <= n; i++) {
        if (nxt[n + 2] != n + 3) { split(nxt[n + 2], pre[n + 3], 0, n + 1); nxt[n + 2] = n + 3, pre[n + 3] = n + 2; }
        if (q.empty()) { ans[++num] = cnt, cnt = 1; u = nxt[0]; remove(u); del[u] = true; } else { u = q.front(); q.pop(); cnt++; }
        for (int j = ls.fst[u]; ~j; j = ls.nxt[j]) {
            int v = ls.v[j];
            if (del[v]) { continue; }
            remove(v); insert(v, pre[n + 3], n + 3);
        }
        for (int j = nxt[0]; j != n + 1; j = nxt[j]) { q.push(j); remove(j); del[j] = true; }
    }
    ans[++num] = cnt;
    printf("%d\n", num - 1);
    return 0;
}