#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5, E = N << 1;

int n, _n, cr, ansu, a[N], siz[N], ss[N];
double ans, f[N], g[N];
bool vis[N];

struct List {
    int tot, fst[N], nxt[E], to[E], val[E];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v, int w) {
        nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; fst[u] = tot++;
    }
    inline void link(int u, int v, int w) {
        insert(u, v, w); insert(v, u, w);
    }
} e;

void findCore(int u, int fa) {
    siz[u] = 1; ss[u] = 0;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i];
        if (v != fa && !vis[v]) {
            findCore(v, u);
            siz[u] += siz[v];
            ss[u] = std::max(ss[u], siz[v]);
        }
    }
    ss[u] = std::max(ss[u], _n - siz[u]);
    if (cr == -1 || ss[cr] > ss[u]) { cr = u; }
}
int getCore(int u, int n) {
    _n = n; cr = -1;
    findCore(u, u);
    return cr;
}

void dfs(int u, int fa, int d) {
    siz[u] = 1; f[u] = sqrt(d) * d * a[u]; g[u] = sqrt(d) * a[u];
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i], w = e.val[i];
        if (v != fa) {
            dfs(v, u, d + w);
            siz[u] += siz[v]; f[u] += f[v]; g[u] += g[v];
        }
    }
    if (vis[u]) { siz[u] = 0; }
}

int solve(int u) {
    vis[u] = true; dfs(u, u, 0);
    if (ansu == -1 || ans > f[u]) { ansu = u; ans = f[u]; }
    double max = -1e18;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i];
        if (!vis[v]) { max = std::max(max, g[v]); }
    }
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i];
        if (!vis[v] && g[v] == max) {
            solve(getCore(v, siz[v])); break;
        }
    }
}

int main() {
    n = read();
    for (int u = 0; u < n; u++) { a[u] = read(); }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(), w = read(); u--; v--;
        e.link(u, v, w);
    }
    ansu = -1; solve(getCore(0, n));
    printf("%d %.6f\n", ansu + 1, ans);
    return 0;
}