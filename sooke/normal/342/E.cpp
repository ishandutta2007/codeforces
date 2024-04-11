#include <cctype>
#include <cstdio>
#include <algorithm>
#include <set>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5;

int n, q, col[N];

struct LinkCutTree {
    std::multiset<int> set[N];
    int vol, stc[N], ft[N], son[N][2], f[N][2], siz[N];
    bool rev[N];

    inline void pushUp(int u) {
        int ls = son[u][0], rs = son[u][1];
        siz[u] = siz[ls] + siz[rs] + 1;
        if (col[u] == 1) {
            f[u][0] = std::min(f[ls][0], siz[ls]);
            f[u][1] = std::min(f[rs][1], siz[rs]);
        } else {
            f[u][0] = std::min(f[ls][0], siz[ls] + 1 + std::min(f[rs][0], *set[u].begin()));
            f[u][1] = std::min(f[rs][1], siz[rs] + 1 + std::min(f[ls][1], *set[u].begin()));
        }
    }
    inline void pushRev(int u) {
        rev[u] ^= 1;
        std::swap(son[u][0], son[u][1]);
        std::swap(f[u][0], f[u][1]);
    }
    inline void pushDown(int u) {
        if (rev[u]) {
            pushRev(son[u][0]);
            pushRev(son[u][1]);
            rev[u] = false;
        }
    }

    inline bool isRight(int u) {
        return son[ft[u]][0] != u;
    }
    inline bool isRoot(int u) {
        return son[ft[u]][0] != u && son[ft[u]][1] != u;
    }
    inline void connect(int u, int fa, int d) {
        ft[u] = fa; son[fa][d] = u;
    }
    inline void rotate(int u) {
        int fa = ft[u], d = isRight(u);
        int ff = ft[fa], fd = isRight(fa), s = son[u][d ^ 1];
        ft[u] = ff;
        if (!isRoot(fa)) { son[ff][fd] = u; }
        connect(s, fa, d); connect(fa, u, d ^ 1);
        pushUp(fa);
    }

    void splay(int u) {
        for (int fa = stc[++vol] = u; !isRoot(fa); fa = stc[++vol] = ft[fa]);
        for (; vol > 0; vol--) { pushDown(stc[vol]); }
        for (int fa = ft[u]; !isRoot(u); rotate(u), fa = ft[u]) {
            if (!isRoot(fa)) { rotate(isRight(u) == isRight(fa) ? fa : u); }
        }
        pushUp(u);
    }
    void access(int u) {
        for (int s = 0; u > 0; s = u, u = ft[u]) {
            splay(u);
            if (son[u][1] > 0) { set[u].insert(f[son[u][1]][0]); }
            if (s > 0) { set[u].erase(set[u].find(f[s][0])); }
            son[u][1] = s;
            pushUp(u);
        }
    }
    void setRoot(int u) {
        access(u); splay(u); pushRev(u);
    }
    void link(int u, int v) {
        setRoot(u); ft[u] = v; set[v].insert(f[u][0]);
    }
} lct;

void modify(int u) {
    lct.setRoot(u); col[u] ^= 1; lct.pushUp(u);
}
int query(int u) {
    lct.setRoot(u); return lct.f[u][0];
}

int main() {
    n = read(); q = read();
    for (int u = 0; u <= n; u++) { lct.f[u][0] = lct.f[u][1] = 1e9; lct.set[u].insert(1e9); }
    for (int u = 1; u <= n; u++) { lct.siz[u] = 1; }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        lct.link(u, v);
    }
    modify(1);
    for (int i = 0; i < q; i++) {
        int opt = read(), u = read();
        if (opt == 1) {
            modify(u);
        } else {
            int ans = query(u);
            printf("%d\n", ans >= 1e8 ? -1 : ans);
        }
    }
    return 0;
}