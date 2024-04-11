#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 40, A = 1 << 20;

int n, m, cnt, vis[N];
long long f[A];
bool flag, e[N][N];

void dfs(int u, int c) {
    if (vis[u]) {
        if (vis[u] != c) { flag = false; }
        return;
    }
    vis[u] = c; cnt++;
    for (int v = 0; v < n; v++) {
        if (e[u][v]) { dfs(v, c ^ 3); }
    }
}
long long solve1() {
    long long res = 1ll << n;
    int num = 0, numa = 1, numb = 0;
    for (int u = 0; u < n; u++) {
        if (!vis[u]) {
            cnt = 0; flag = true; num++; dfs(u, 1);
            if (!flag) { numb = -1; }
            if (cnt == 1) { numa++; }
            if (numb != -1) { numb++; }
        }
    } res += -(1ll << num) + (1ll << numa);
    if (numb != -1) { res += 1ll << numb; }
    if (m == 0) { res -= 1ll << n; }
    return res;
}

void fwt(long long f[], int n) {
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; j++) {
                f[i + j + len] += f[i + j];
            }
        }
    }
}
long long solve2() {
    long long res = 0;
    int nl = n / 2, nr = n - nl, al = 1 << nl, ar = 1 << nr;
    for (int i = 0; i < al; i++) {
        f[i] = 1;
        for (int u = 0; u < nl; u++) {
            for (int v = 0; v < u; v++) {
                if (e[u][v] && (1ll << u & i) && (1ll << v & i)) { f[i] = 0; }
            }
        }
    } fwt(f, al);
    for (int i = 0; i < ar; i++) {
        bool flag = true;
        for (int u = nl; u < n; u++) {
            for (int v = nl; v < u; v++) {
                if (e[u][v] && (1ll << u - nl & i) && (1ll << v - nl & i)) { flag = false; }
            }
        }
        if (!flag) { continue; }
        int j = al - 1;
        for (int u = 0; u < nl; u++) {
            for (int v = nl; v < n; v++) {
                if (e[u][v] && (1ll << u & j) && (1ll << v - nl & i)) { j ^= 1ll << u; }
            }
        } res += f[j];
    } return res * 2;
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(); u--; v--;
        e[u][v] = e[v][u] = true;
    } printf("%I64d\n", solve1() - solve2());
    return 0;
}