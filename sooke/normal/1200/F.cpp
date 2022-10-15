#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e3 + 5, M = 2520;

int modul(int x) { return (x % M + M) % M; }

int n, q, col, nowcol, tcol, tf, endu, endx, cnt;
int a[N], p[N], e[N][10], f[N][M], g[N * M], c[N][M], nowc[N][M];
bool used[N];

void dfs1(int u, int x) {
    if (c[u][x] > 0) {
        tcol = c[u][x]; tf = f[u][x]; return;
    }
    if (nowc[u][x] == nowcol) {
        endu = u; endx = x; return;
    }
    nowc[u][x] = nowcol;
    dfs1(e[u][(x + a[u]) % p[u]], (x + a[u]) % M);
}
void dfs2(int u, int x) {
    if (c[u][x] > 0) { return; }
    c[u][x] = tcol; f[u][x] = tf;
    dfs2(e[u][(x + a[u]) % p[u]], (x + a[u]) % M);
}
void dfs3(int u, int x, bool fst) {
    if (u == endu && x == endx && fst == false) { return; }
    if (used[u] == false) { cnt++; }
    used[u] = true;
    dfs3(e[u][(x + a[u]) % p[u]], (x + a[u]) % M, false);
}
void dfs4(int u, int x, bool fst) {
    if (u == endu && x == endx && fst == false) { return; }
    used[u] = false; f[u][x] = cnt; c[u][x] = col;
    dfs4(e[u][(x + a[u]) % p[u]], (x + a[u]) % M, false);
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) { a[i] = modul(read()); }
    for (int i = 0; i < n; i++) {
        p[i] = read();
        for (int j = 0; j < p[i]; j++) { e[i][j] = read(); e[i][j]--; }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            nowcol++; tcol = 0; dfs1(i, j);
            if (tcol > 0) { dfs2(i, j); } else {
                cnt = 0; dfs3(endu, endx, true);
                col++; dfs4(endu, endx, true);
                tcol = col; tf = f[endu][endx];
                dfs2(i, j);
            }
        }
    }
    q = read();
    for (int i = 0; i < q; i++) {
        int u = read(), x = modul(read()); u--;
        printf("%d\n", f[u][x]);
    }
    return 0;
}