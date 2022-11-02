#include <bits/stdc++.h>

inline void read(int &x) {
    int c;
    while (!isdigit(c = getchar()));
    x = c - '0';
    while (isdigit(c = getchar())) {
        (x *= 10) += c - '0';
    }
}

const int max_N = (int) 2e6 + 21;
const int M = 65535;
const int max_M = M + 21;

int n, f[max_N], siz[max_N], sum[max_N], fir[max_N], sec[max_N];

int hash[max_N], head[max_M], next[max_N], tot;

inline int getid(int x) {
    int y = x & M;
    for (int i = head[y]; i; i = next[i])
        if (hash[i] == x) {
            return i;
        }
    hash[++tot] = x, next[tot] = head[y], head[y] = tot;
    f[tot] = tot, siz[tot] = 1, sum[tot] = 0, fir[tot] = x, sec[tot] = 0;
    return tot;
}

inline int find(int x) {
    int r, y;
    for (r = x; r != f[r]; r = f[r]);
    for (; x != r; y = f[x], f[x] = r, x = y);
    return r;
}

inline void updt(int u, int a) {
    if (fir[u] < a) {
        sec[u] = fir[u];
        fir[u] = a;
    } else if (sec[u] < a) {
        sec[u] = a;
    }
}

inline void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) {
        ++sum[u];
        return;
    }
    if (siz[u] > siz[v]) std::swap(u, v);
    f[u] = v;
    siz[v] += siz[u];
    sum[v] += sum[u] + 1;
    updt(v, fir[u]);
    updt(v, sec[u]);
}

int ans;

int main() {
    read(n);
    for (int i = 1, a, b; i <= n; ++i) {
        read(a), read(b);
        merge(getid(a), getid(b));
    }
    for (int i = 1; i <= tot; ++i) {
        if (f[i] != i) continue;
        if (sum[i] > siz[i]) return puts("-1"), 0;
        if (sum[i] == siz[i]) ans = std::max(ans, fir[i]);
        else ans = std::max(ans, sec[i]);
    }
    printf("%d\n", ans);
    return 0;
}