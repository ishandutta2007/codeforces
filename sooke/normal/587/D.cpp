#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 5e5 + 5;

int n, m, tot, ans, a[N], b[N], pre[N], suf[N];
int tms, dfn[N], low[N], vol, stc[N], num, col[N];
bool ins[N];
std::vector<int> e[N], adj[N], used;

bool compare(int i, int j) {
    return a[i] < a[j];
}

inline int get(int u, int x) {
    return u * 2 + x;
}
inline void link(int u, int x, int v, int y) {
    e[get(u, x)].push_back(get(v, y));
    e[get(v, y ^ 1)].push_back(get(u, x ^ 1));
}

void tarjan(int u) {
    dfn[u] = low[u] = tms++; stc[++vol] = u;
    int pos = vol; ins[u] = true;
    for (auto v : e[u]) {
        if (dfn[v] == -1) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        for (int i = pos; i <= vol; i++) {
            int u = stc[i];
            ins[u] = false; col[u] = num;
        }
        vol = pos - 1; num++;
    }
}

bool check(int mid) {
    num = 0; tot = m;
    for (int u = 0; u < m * 10; u++) {
        e[u].clear(); dfn[u] = -1;
    }
    for (int s = 1; s <= n; s++) {
        for (int _ = 1; _ < adj[s].size(); _++) {
            int i = adj[s][_], j = adj[s][_ - 1];
            if (a[i] != a[j]) { continue; }
            link(i, 1, j, 0);
        }
        for (int _ = 0; _ < adj[s].size(); _++) {
            int i = adj[s][_];
            if (b[i] > mid) { link(i, 0, i, 1); }
            pre[i] = ++tot; suf[i] = ++tot;
        }
        for (int _ = 0; _ < adj[s].size(); _++) {
            int i = adj[s][_];
            link(i, 0, pre[i], 0);
            if (i != adj[s].front()) {
                int j = adj[s][_ - 1];
                link(pre[j], 0, i, 1);
                link(pre[j], 0, pre[i], 0);
            }
            link(i, 0, suf[i], 0);
            if (i != adj[s].back()) {
                int j = adj[s][_ + 1];
                link(suf[j], 0, i, 1);
                link(suf[j], 0, suf[i], 0);
            }
        }
    }
    for (int u = 0; u < m * 10; u++) {
        if (dfn[u] == -1) { tarjan(u); }
    }
    for (int i = 0; i < m * 5; i++) {
        if (col[get(i, 0)] == col[get(i, 1)]) { return false; }
    }
    return true;
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        a[i] = read(); b[i] = read();
        adj[u].push_back(i); adj[v].push_back(i);
    }
    for (int s = 1; s <= n; s++) {
        std::sort(adj[s].begin(), adj[s].end(), compare);
        for (int _ = 2; _ < adj[s].size(); _++) {
            int i = adj[s][_], j = adj[s][_ - 1], k = adj[s][_ - 2];
            if (a[i] == a[j] && a[j] == a[k]) { printf("No\n"); exit(0); }
        }
    }
    for (int l = 0, r = 1e9, mid; l <= r; ) {
        mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1; ans = mid;
        } else {
            l = mid + 1;
        }
    }
    if (!check(ans)) { printf("No\n"); exit(0); }
    for (int i = 0; i < m; i++) {
        if (col[get(i, 0)] < col[get(i, 1)]) {
            used.push_back(i);
        }
    }
    printf("Yes\n%d %d\n", ans, used.size());
    for (auto i : used) { printf("%d ", i + 1); }
    return 0;
}