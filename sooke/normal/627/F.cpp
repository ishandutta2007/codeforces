#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, k, s, t, rs, rt, len, ans0, a[N], b[N], ft[N], dis[N], dit[N], deg[N];
long long ans1;
std::vector<int> e[N], ed;

bool dfs0(int u, int fa) {
    if (u == s) { return true; }
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        if (dfs0(v, u)) {
            std::swap(a[u], a[v]); ans0++;
            return true;
        }
    }
    return false;
}
void dfs1(int u, int fa) {
    ft[u] = fa; dit[u] = dit[fa] + 1;
    if (a[u] != b[u]) { deg[fa]++; }
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        dfs1(v, u);
    }
}
void dfs2(int u, int fa) {
    dis[u] = dis[fa] + 1;
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        dfs2(v, u);
    }
}

bool check0() {
    for (int u = 1; u <= n; u++) {
        if (a[u] != b[u]) { return false; }
    }
    return true;
}
bool check1() {
    rt = -1;
    for (int u = 1; u <= n; u++) {
        if (a[u] == b[u]) {
            if (deg[u] > 2) { return false; }
            if (deg[u] != 0) {
                if (rt != -1) { return false; }
                rt = u;
            }
        } else {
            if (deg[u] > 1) { return false; }
            if (deg[u] == 0) { ed.push_back(u); }
            len++;
        }
    }
    if (ed.size() > 2) { return false; }
    if (ed.size() < 2) { ed.push_back(rt); }
    rs = s;
    for (; rs != t && a[rs] == b[rs]; rs = ft[rs]);
    if (rs == t) { rs = rt; }
    for (int u = ed[0]; u != rt; u = ft[u]) {
        if (a[u] == b[ed[0]]) { k = dit[ed[0]] - dit[u]; }
    }
    for (int u = ed[1]; u != rt; u = ft[u]) {
        if (a[u] == b[ed[0]]) { k = len - (dit[ed[1]] - dit[u] + 1); }
    }
    for (int u = ed[0]; u != rt; u = ft[u]) {
        if (u == rs) { k = len - k; }
    }
    return true;
}

int main() {
    n = read();
    for (int u = 1; u <= n; u++) {
        a[u] = read();
        if (a[u] == 0) { s = u; }
    }
    for (int u = 1; u <= n; u++) {
        b[u] = read();
        if (b[u] == 0) { t = u; }
    }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v); e[v].push_back(u);
    }
    dfs0(t, 0);
    if (check0()) { printf("0 %d\n", ans0); return 0; }
    dis[0] = dit[0] = -1;
    dfs1(t, 0); dfs2(s, 0);
    if (!check1()) { printf("-1\n"); return 0; }
    if (rs == rt) {
        ans1 = dis[rs] + dit[rt] + 1ll * std::min(k, len - k) * (len + 1);
    } else {
        int mid = dis[rt] - dis[rs];
        ans1 = dis[rs] + dit[rt] + std::min(k * (len + 1ll) - mid, (len - k) * (len + 1ll) + mid);
    }
    std::sort(ed.begin(), ed.end());
    printf("%d %d %lld\n", ed[0], ed[1], ans1);
    return 0;
}