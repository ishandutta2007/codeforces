#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const double eps = 1e-7;

const int N = 1e6 + 5, L = 21;

int n, q, ft[N], dep[N], siz[N], hs[N], top[N], dfn[N];
int m, k, sa[N], rk[N], old[N], buc[N], ht[N], lgm, o[N], st[L][N];
char str[N], _str[N];
std::vector<int> e[N];

void dfs1(int u, int fa) {
    ft[u] = fa; dep[u] = dep[fa] + 1; siz[u] = 1;
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[hs[u]] < siz[v]) { hs[u] = v; }
    }
}
void dfs2(int u, int tp) {
    top[u] = tp; dfn[u] = ++m;
    str[m] = str[n * 2 + 1 - m] = _str[u];
    if (hs[u] > 0) { dfs2(hs[u], tp); }
    for (auto v : e[u]) {
        if (v == ft[u] || v == hs[u]) { continue; }
        dfs2(v, v);
    }
}

void radixSort() {
    for (int i = 1; i <= k; i++) { buc[i] = 0; }
    for (int i = 1; i <= m; i++) { buc[rk[i]]++; }
    for (int i = 1; i <= k; i++) { buc[i] += buc[i - 1]; }
    for (int i = m; i >= 1; i--) { sa[buc[rk[old[i]]]--] = old[i]; }
}
void suffixSort() {
    for (int i = 1; i <= m; i++) {
        rk[i] = str[i] - 'a' + 1; old[i] = i;
    }
    k = *std::max_element(rk + 1, rk + m + 1);
    radixSort();
    for (int len = 1, num; ; len *= 2) {
        num = 0;
        for (int i = 1; i <= len; i++) {
            old[++num] = m + 1 - i;
        }
        for (int i = 1; i <= m; i++) {
            if (sa[i] > len) { old[++num] = sa[i] - len; }
        }
        radixSort();
        memcpy(old, rk, (m + 1) * 4);
        rk[sa[1]] = k = 1;
        for (int i = 2; i <= m; i++) {
            if (old[sa[i]] == old[sa[i - 1]] && old[sa[i] + len] == old[sa[i - 1] + len]) {
                rk[sa[i]] = k;
            } else {
                rk[sa[i]] = ++k;
            }
        }
        if (k == m) { break; }
    }
    for (int i = 1, j, num = 0; i <= m; i++) {
        if (rk[i] == 1) { ht[rk[i]] = num = 0; continue; }
        j = sa[rk[i] - 1]; num = num ? num - 1 : 0;
        for (; str[i + num] == str[j + num]; num++);
        ht[rk[i]] = num;
    }
}

void build() {
    for (int i = 1; i <= m; i++) {
        o[i] = log(i) / log(2) + eps;
        st[0][i] = ht[i];
    }
    lgm = o[m];
    for (int j = 1; j <= lgm; j++) {
        for (int i = 1; i + (1 << j) - 1 <= m; i++) {
            st[j][i] = std::min(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
        }
    }
}
int query(int l, int r) {
    if (l == r) { return m + 1 - l; }
    l = rk[l]; r = rk[r];
    if (l > r) { std::swap(l, r); }
    l++;
    int lgl = o[r - l + 1];
    return std::min(st[lgl][l], st[lgl][r - (1 << lgl) + 1]);
}

void split(int u, int v, std::vector<std::pair<int, int>> &res) {
    std::vector<std::pair<int, int>> rev;
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            res.push_back({m + 1 - dfn[u], m + 1 - dfn[top[u]]});
            u = ft[top[u]];
        } else {
            rev.push_back({dfn[top[v]], dfn[v]});
            v = ft[top[v]];
        }
    }
    if (dep[u] > dep[v]) {
        res.push_back({m + 1 - dfn[u], m + 1 - dfn[v]});
    } else {
        rev.push_back({dfn[u], dfn[v]});
    }
    std::reverse(rev.begin(), rev.end());
    for (auto i : rev) { res.push_back(i); }
}

int main() {
    n = read();
    scanf("%s", _str + 1);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v); e[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 1);
    m *= 2; str[m + 1] = '*';
    suffixSort(); build();
    q = read();
    for (; q; q--) {
        int s1 = read(), t1 = read(), s2 = read(), t2 = read();
        std::vector<std::pair<int, int>> a, b;
        split(s1, t1, a); split(s2, t2, b);
        int ans = 0, i = 0, j = 0, d1 = 0, d2 = 0;
        while (i < a.size() && j < b.size()) {
            int lcp = query(a[i].first + d1, b[j].first + d2);
            lcp = std::min(lcp, std::min(a[i].second - a[i].first - d1, b[j].second - b[j].first - d2) + 1);
            if (lcp == 0) { break; }
            ans += lcp; d1 += lcp; d2 += lcp;
            if (a[i].first + d1 > a[i].second) { i++; d1 = 0; }
            if (b[j].first + d2 > b[j].second) { j++; d2 = 0; }
        }
        printf("%d\n", ans);
    }
    return 0;
}