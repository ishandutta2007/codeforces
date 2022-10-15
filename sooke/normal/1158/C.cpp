#include <cstdio>
#include <cstring>
#include <vector>

const int N = 500005;

int t, n, tms, a[N], ans[N];
std::vector<int> e[N];

struct FenwickTree {
    int f[N];

    void modify(int u, int x) {
        for (; u; u ^= u & -u) { f[u] = std::min(f[u], x); }
    }
    int query(int u) {
        int res = n;
        for (; u <= n; u += u & -u) { res = std::min(res, f[u]); }
        return res;
    }
} bit;

void dfs(int u) {
    for (auto v : e[u]) { dfs(v); }
    ans[u] = ++tms;
}

bool check() {
    memset(bit.f, 127, sizeof(int) * (n + 1)); bit.modify(n, n);
    for (int i = n - 1; i; i--) {
        if (bit.query(ans[i]) != a[i]) { return false; }
        bit.modify(ans[i], i);
    }
    return true;
}

int main() {
    for (scanf("%d", &t); t; t--) {
        for (int i = 1; i <= n; i++) { e[i].clear(); }
        scanf("%d", &n); n++; tms = 0;
        for (int i = 1; i < n; i++) {
            scanf("%d", &a[i]); a[i] = std::max(a[i], i + 1);
        }
        for (int i = n - 1; i; i--) { e[a[i]].push_back(i); }
        dfs(n);
        if (check()) {
            for (int i = 1; i < n - 1; i++) { printf("%d ", ans[i]); }
            printf("%d\n", ans[n - 1]);
        } else { printf("-1\n"); }
    }
    return 0;
}