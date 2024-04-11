#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, a[N], b[N], anc[N], siz[N], tag[N];

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

int solve() {
    for (int i = 1; i <= n; i++) {
        anc[i] = i; siz[i] = 0; tag[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans += a[i] != b[i];
        int u = find(a[i]), v = find(b[i]);
        if (u != v) { anc[u] = v; }
    }
    for (int i = 0; i < m; i++) {
        tag[find(a[i])]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        siz[find(i)]++;
    }
    for (int i = 1; i <= n; i++) {
        res += find(i) == i && siz[i] > 1 && tag[i] == siz[i];
    }
    ans += res;
    return ans;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        for (int i = 0; i < m; i++) {
            a[i] = read(); b[i] = read();
        }
        printf("%d\n", solve());
    }
    return 0;
}