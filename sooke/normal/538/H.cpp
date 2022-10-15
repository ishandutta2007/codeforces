#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5, L = 19;

int n, m, nl, nr, al[N], ar[N], num, tb[N], col[N], rt[N], s[N][3], t[N][3], o[N], l[L][N], r[L][N], ans[N];
bool swap[N];
std::vector<int> e[N];

void dfs(int u, int fa, int c) {
    if (col[u] > 0 && col[u] != c) { printf("IMPOSSIBLE\n"); exit(0); }
    if (col[u] > 0) { return; }
    col[u] = c; rt[u] = fa;
    s[fa][c] = std::max(s[fa][c], al[u]);
    t[fa][c] = std::min(t[fa][c], ar[u]);
    for (auto v : e[u]) { dfs(v, fa, c ^ 3); }
}

void solve(int z, int x, int y) {
    if (tb[z] > x || x >= tb[z + 1]) { return; }
    if (tb[l[0][z]] > y || y >= tb[r[0][z]]) { return; }
    if (nl > 0ll + x + y || 0ll + x + y > nr) { return; }
    printf("POSSIBLE\n");
    printf("%d %d\n", x, y);
    for (int u = 1; u <= n; u++) {
        if (rt[u] != u) { continue; }
        ans[u] = swap[u] ? 0 : 3;
        if (tb[s[u][1]] > x || x >= tb[t[u][1]]) { continue; }
        if (tb[s[u][2]] > y || y >= tb[t[u][2]]) { continue; }
        ans[u] = swap[u] ? 3 : 0;
    }
    for (int u = 1; u <= n; u++) {
        printf("%d", ans[rt[u]] ^ col[u]);
    }
    exit(0);
}

inline void modify(int i, int j, int x, int y) {
    if (i == j) { return; }
    int lgl = o[j - i];
    l[lgl][i] = std::max(l[lgl][i], x);
    r[lgl][i] = std::min(r[lgl][i], y);
    int k = j - (1 << lgl);
    l[lgl][k] = std::max(l[lgl][k], x);
    r[lgl][k] = std::min(r[lgl][k], y);
}

int main() {
    nl = read(); nr = read();
    n = read(); m = read();
    for (int u = 1; u <= n; u++) {
        al[u] = read(); tb[num++] = al[u];
        ar[u] = read(); tb[num++] = ++ar[u];
    }
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        e[u].push_back(v); e[v].push_back(u);
    }
    tb[num++] = 0;
    std::sort(tb, tb + num);
    num = std::unique(tb, tb + num) - tb;
    tb[num] = 2e9;
    for (int u = 1; u <= n; u++) {
        al[u] = std::lower_bound(tb, tb + num, al[u]) - tb;
        ar[u] = std::lower_bound(tb, tb + num, ar[u]) - tb;
    }
    for (int i = 1; i <= num; i++) {
        o[i] = log(i) / log(2) + 1e-7;
    }
    for (int j = 0; j <= o[num]; j++) {
        for (int i = 0; i < num; i++) {
            l[j][i] = 0; r[j][i] = num;
        }
    }
    for (int u = 1; u <= n; u++) {
        if (rt[u] > 0) { continue; }
        s[u][1] = 0; t[u][1] = num;
        s[u][2] = 0; t[u][2] = num;
        dfs(u, u, 1);
        if (s[u][1] >= t[u][1]) { printf("IMPOSSIBLE\n"); exit(0); }
        if (s[u][2] >= t[u][2]) { printf("IMPOSSIBLE\n"); exit(0); }
        if (s[u][1] >= s[u][2]) {
            swap[u] = true;
            std::swap(s[u][1], s[u][2]);
            std::swap(t[u][1], t[u][2]);
        }
        if (s[u][2] >= t[u][1]) {
            modify(0, s[u][1], num, 0);
            modify(s[u][1], t[u][1], s[u][2], t[u][2]);
            modify(t[u][1], s[u][2], num, 0);
            modify(s[u][2], t[u][2], s[u][1], t[u][1]);
            modify(t[u][2], num, num, 0);
        } else if (t[u][2] <= t[u][1]) {
            modify(0, s[u][1], num, 0);
            modify(s[u][1], s[u][2], s[u][2], t[u][2]);
            modify(s[u][2], t[u][2], s[u][1], t[u][1]);
            modify(t[u][2], t[u][1], s[u][2], t[u][2]);
            modify(t[u][1], num, num, 0);
        } else {
            modify(0, s[u][1], num, 0);
            modify(s[u][1], s[u][2], s[u][2], t[u][2]);
            modify(s[u][2], t[u][1], s[u][1], t[u][2]);
            modify(t[u][1], t[u][2], s[u][1], t[u][1]);
            modify(t[u][2], num, num, 0);
        }
    }
    for (int j = o[num]; j > 0; j--) {
        for (int i = 0; i < num; i++) {
            l[j - 1][i] = std::max(l[j - 1][i], l[j][i]);
            r[j - 1][i] = std::min(r[j - 1][i], r[j][i]);
            int k = i + (1 << j - 1);
            if (k >= num) { continue; }
            l[j - 1][k] = std::max(l[j - 1][k], l[j][i]);
            r[j - 1][k] = std::min(r[j - 1][k], r[j][i]);
        }
    }
    for (int i = 0; i < num; i++) {
        if (l[0][i] >= r[0][i]) { continue; }
        solve(i, tb[i], tb[l[0][i]]);
        solve(i, tb[i + 1] - 1, tb[r[0][i]] - 1);
        solve(i, tb[i], nl - tb[i]);
        solve(i, tb[i + 1] - 1, nr - (tb[i + 1] - 1));
    }
    printf("IMPOSSIBLE\n");
    return 0;
}