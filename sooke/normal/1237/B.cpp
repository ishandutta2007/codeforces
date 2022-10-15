#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, ans, p[N], q[N], pos[N];
std::set<int> set;

int main() {
    n = read();
    for (int i = 0; i < n; i++) { p[i] = read(); }
    for (int i = 0; i < n; i++) { q[i] = read(); pos[q[i]] = i; }
    for (int i = 0; i < n; i++) {
        int u = p[i];
        if (set.lower_bound(pos[u]) != set.end()) { ans++; }
        set.insert(pos[u]);
    }
    printf("%d\n", ans);
    return 0;
}