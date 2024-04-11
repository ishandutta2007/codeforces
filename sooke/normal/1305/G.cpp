#include <cctype>
#include <cstdio>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1 << 20;

int n, lim, cnt[N];
long long ans;

struct DisjointSet {
    int anc[N], siz[N];
    
    void reset(int n) {
        for (int u = 0; u <= n; u++) { anc[u] = u; siz[u] = 1; }
    }
    int find(int u) {
        return anc[u] == u ? u : anc[u] = find(anc[u]);
    }
    bool merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) { return false; }
        if (siz[u] < siz[v]) {
            anc[u] = v; siz[v] += siz[u];
        } else  {
            anc[v] = u; siz[u] += siz[v];
        }
        return true;
    }
} ds;

int main() {
    n = read(); lim = (1 << 18) - 1;
    cnt[0]++; ds.reset(lim);
    for (int i = 0; i < n; i++) {
        int x = read();
        cnt[x]++; ans -= x;
    }
    for (int i = lim; i > 0; i--) {
        for (int s = i, t; ; s = (s - 1) & i) {
            t = i ^ s;
            if (cnt[s] > 0 && cnt[t] > 0 && ds.merge(s, t)) {
                ans += (cnt[s] + cnt[t] - 1ll) * i;
                cnt[s] = 1; cnt[t] = 1;
            }
            if (s == 0) { break; }
        }
    }
    printf("%lld\n", ans);
    return 0;
}