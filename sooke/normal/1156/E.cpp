#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline int read() {
    char c = getchar(); int x = 0; bool sgn = false;
    while (c < '0' || c > '9') { if (c == '-') { sgn = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return sgn ? -x : x;
}

const int N = 200005, L = 19;

int n, a[N], o[N], st[L][N];
std::set<int> emp;
long long ans;

void build() {
    for (int i = 1; i <= n; i++) { o[i] = log(i) / log(2) + 1e-7; }
    for (int i = 1; i <= o[n]; i++) {
        for (int j = 1, u, v; j + (1 << i) - 1 <= n; j++) {
            u = st[i - 1][j]; v = st[i - 1][j + (1 << i - 1)];
            st[i][j] = a[u] > a[v] ? u : v;
        }
    }
}
inline int query(int l, int r) {
    int d = o[r - l + 1], u = st[d][l], v = st[d][r - (1 << d) + 1];
    return a[u] > a[v] ? u : v;
}

std::set<int> dfs(int l, int r) {
    if (l > r) { return emp; }
    int mid = query(l, r);
    std::set<int> s = dfs(l, mid - 1);
    std::set<int> t = dfs(mid + 1, r);
    if (s.size() <= t.size()) {
        for (auto u : s) { ans += t.count(a[mid] - u); }
        for (auto u : s) { t.insert(u); }
        t.insert(a[mid]); return t;
    } else {
        for (auto u : t) { ans += s.count(a[mid] - u); }
        for (auto u : t) { s.insert(u); }
        s.insert(a[mid]); return s;
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); st[0][i] = i; }
    build(); dfs(1, n); printf("%I64d\n", ans);
    return 0;
}