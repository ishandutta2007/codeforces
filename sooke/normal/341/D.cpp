#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

typedef long long lol;

inline lol read() {
    char c = getchar(); lol n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 1005;

int n, m;

struct TreeArray {
    lol c[4][maxN][maxN];

    inline int lowbit(int u) { return u & -u; }
    void modify(int x, int y, lol w) {
        int id = (x & 1) << 1 | (y & 1);
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= n; j += lowbit(j)) { c[id][i][j] ^= w; }
        }
    }
    lol query(int x, int y) {
        int id = (x & 1) << 1 | (y & 1); lol res = 0;
        for (int i = x; i; i ^= lowbit(i)) {
            for (int j = y; j; j ^= lowbit(j)) { res ^= c[id][i][j]; }
        }
        return res;
    }
} tr;

int main() {
    n = read();
    for (m = read(); m; m--) {
        int opt = read(), ax = read(), ay = read(), bx = read(), by = read();
        if (opt == 1) {
            printf("%I64d\n", tr.query(bx, by) ^ tr.query(bx, ay - 1) ^ tr.query(ax - 1, by) ^ tr.query(ax - 1, ay - 1));
        } else {
            lol w = read();
            tr.modify(bx + 1, by + 1, w), tr.modify(bx + 1, ay, w), tr.modify(ax, by + 1, w), tr.modify(ax, ay, w);
        }
    }
    return 0;
}

///3\45/\34/5\/34\5/\23/\/5t\/\dfs/gfsdx\sg/