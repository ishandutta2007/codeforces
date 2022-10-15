#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e6 + 5, E = 1e7 + 5;

struct List {
    int tot, fst[N], nxt[E], to[E];

    void reset(int n) {
        memset(fst, -1, sizeof(int) * (n)); tot = 0;
    }
    inline void insert(int u, int v) {
        nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++;
    }
} e;

int n, m, c, tms, vol, dfn[N], low[N], stc[N], col[N], deg[N], ans[N];
std::vector<int> a, b;
bool ins[N];


void tarjan(int u) {
    dfn[u] = low[u] = tms++;
    int pos = vol; stc[vol++] = u; ins[u] = true;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i];
        if (dfn[v] == -1) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        while (vol > pos) {
            int v = stc[--vol];
            col[v] = c; ins[v] = false;
        }
        c++;
    }
}

void dfs(int u) {
    if (deg[col[u]] > 0) { return; }
    if (ans[u] == 0) { return; }
    ans[u] = 0;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i]; dfs(v);
    }
}

bool solve() {
    if (n <= 1) { return false; }
    c = tms = 0;
    for (int i = 0; i < n; i++) { dfn[i] = -1; deg[i] = 0; }
    for (int i = 0; i < n; i++) {
        if (dfn[i] == -1) { tarjan(i); }
    }
    for (int u = 0; u < n; u++) {
        for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
            int v = e.to[i];
            if (col[u] != col[v]) { deg[col[v]]++; }
        }
    }
    for (int i = 0; i < n; i++) { ans[i] = 1; }
    for (int i = 0; i < n; i++) {
        if (deg[col[i]] == 0) {
            dfs(i); break;
        }
    }
    a.clear(); b.clear();
    for (int i = 0; i < n; i++) {
        if (ans[i] == 1) {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    if (a.empty() || b.empty()) { return false; }
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read(); e.reset(n);
        for (int i = 0; i < m; i++) {
            int u = read(), v = read(); u--; v--;
            e.insert(u, v);
        }
        if (solve()) {
            printf("YES\n%d %d\n", a.size(), b.size());
            for (auto i : a) { printf("%d ", i + 1); } printf("\n");
            for (auto i : b) { printf("%d ", i + 1); } printf("\n");
        } else {
            printf("NO\n");
        }        
    }
    return 0;
}