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

int n, a[200005];
std::pair<int, int> p[200005];
std::set<int> set;

void check(int x) {
    int res = -1;
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] != x) {
            if (i == n || a[i + 1] - a[i - 1] == x) {
                if (res == -1) { res = i; i++; } else { return; }
            } else { return; }
        }
    }
    if (res != -1) { printf("%d\n", p[res].second); exit(0); }
}
void check2() {
    for (int i = 3; i <= n; i++) {
        if (a[i] - a[i - 1] != a[3] - a[2]) { return; }
    }
    printf("%d\n", p[1].second); exit(0);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { p[i] = {read(), i}; }
    std::sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) { a[i] = p[i].first; }
    for (int i = 2; i <= n; i++) { set.insert(a[i] - a[i - 1]); }
    if (set.size() == 1) { printf("%d\n", p[1].second); }
    else if (set.size() <= 3) {
        for (auto x : set) { check(x); } check2(); printf("-1\n"); 
    } else { printf("-1\n"); }
    return 0;
}