#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n, u = 0;
std::vector<std::pair<int, int>> e;

bool check(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) { return false; }
    }
    return true;
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) { e.push_back({i, (i + 1) % n}); }
    while (!check(e.size())) {
        if (u < (u ^ 2)) { e.push_back({u, u ^ 2}); }
        u++;
    }
    printf("%u\n", e.size());
    for (auto p : e) { printf("%d %d\n", p.first + 1, p.second + 1); }
    return 0;
}