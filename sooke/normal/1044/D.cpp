#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 2000005;

int m, ans, num, fth[maxN];
std::map<int, int> map;

struct LinkCutTree {
    int vol, stack[maxN], son[2][maxN], fa[maxN], val[maxN], sum[maxN]; bool rev[maxN];

    inline bool isRight(int u) { return son[1][fa[u]] == u; }
    inline bool isRoot(int u) { return son[0][fa[u]] != u && son[1][fa[u]] != u; }
    inline void pushUp(int u) { sum[u] = sum[son[0][u]] ^ sum[son[1][u]] ^ val[u]; }
    inline void pushRev(int u) { if (u) { rev[u] ^= 1; std::swap(son[0][u], son[1][u]); } } 
    inline void pushDown(int u) { if (rev[u]) { pushRev(son[0][u]); pushRev(son[1][u]); rev[u] = false; } }
    inline void connect(int u, int f, int dir) { fa[u] = f; son[dir][f] = u; }
    inline void rotate(int u) {
        int f = fa[u], g = fa[f], dir = isRight(u), fdir = isRight(f), s = son[dir ^ 1][u];
        fa[u] = g; if (!isRoot(f)) { son[fdir][g] = u; }
        connect(s, f, dir); connect(f, u, dir ^ 1); pushUp(f); pushUp(u);
    }
    void splay(int u) {
        for (int f = stack[vol = 1] = u; !isRoot(f); f = stack[++vol] = fa[f]) { }
        for (; vol; vol--) { pushDown(stack[vol]); }
        for (int f = fa[u]; !isRoot(u); rotate(u), f = fa[u]) { if (!isRoot(f)) { rotate(isRight(u) == isRight(f) ? f : u); } }
    }
    void access(int u) { for (int s = 0; u; u = fa[s = u]) { splay(u); son[1][u] = s; pushUp(u); } }
    void setRoot(int u) { access(u); splay(u); pushRev(u); }
    void split(int u, int v) { setRoot(v); access(u); splay(u); }
    void link(int u, int v) { setRoot(u); fa[u] = v; }
    int query(int u, int v) { split(u, v); return sum[u]; }
} tr;

int find(int u) { return fth[u] == u ? u : fth[u] = find(fth[u]); }

inline int query(int l, int r) {
    if (!map[l] || !map[r]) { return -1; }
    int u = find(map[l]), v = find(map[r]);
    return u == v ? tr.query(map[l], map[r]) : -1;
}
inline void modify(int l, int r, int x) {
    if (!map[l]) { map[l] = ++num; fth[num] = num; }
    if (!map[r]) { map[r] = ++num; fth[num] = num; }
    num++; tr.val[num] = tr.sum[num] = x; fth[num] = num;
    tr.link(map[l], num); tr.link(num, map[r]);
    int u = find(map[l]), v = find(map[r]); fth[u] = num; fth[v] = num;
}

int main() {
    for (m = read(); m; m--) {
        int opt = read(), l = read() ^ ans, r = read() ^ ans;
        if (l > r) { std::swap(l, r); }
        if (opt == 1) {
            if (query(l - 1, r) == -1) { modify(l - 1, r, read() ^ ans); } else { read(); }
        } else { printf("%d\n", ans = query(l - 1, r)); ans = std::abs(ans); }
    }
    return 0;
} //