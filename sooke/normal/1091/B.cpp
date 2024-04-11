#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 1005;

int n, x[maxN], y[maxN], s[maxN], t[maxN];
std::set<std::pair<int, int> > set;

bool check(int u, int v) {
    for (int i = 2; i <= n; i++) {
        if (set.count({u - x[i], v - y[i]}) == 0) { return false; }
    }
    return true;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        s[i] = read(), t[i] = read();
        set.insert({s[i], t[i]});
    }
    for (int i = 1; i <= n; i++) { x[i] = read(); y[i] = read(); }
    for (int i = 1; i <= n; i++) {
        int u = s[1] + x[i], v = t[1] + y[i];
        if (check(u, v)) { printf("%d %d\n", u, v); break; }
    }
    return 0;
} //