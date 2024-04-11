#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 22;

int n, m, dd, a[1 << N];
std::vector<int> ans;
long long sum;

void check(int u, int d) {
    int ls = u << 1, rs = ls | 1;
    if (a[ls] == 0 && a[rs] == 0) { dd = d; return; }
    if (a[ls] > a[rs]) {
        check(ls, d + 1);
    } else {
        check(rs, d + 1);
    }
}
void erase(int u) {
    int ls = u << 1, rs = ls | 1;
    if (a[ls] == 0 && a[rs] == 0) { a[u] = 0; return; }
    if (a[ls] > a[rs]) {
        a[u] = a[ls]; erase(ls);
    } else {
        a[u] = a[rs]; erase(rs);
    }
}

void solve(int u, int d) {
    if (u == 0 || d > m) { return; }
    int ls = u << 1, rs = ls | 1;
    check(u, d);
    if (dd <= m) {
        sum += a[u];
        solve(ls, d + 1); solve(rs, d + 1);
    } else {
        ans.push_back(u);
        erase(u);
        solve(u, d);
    }
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        for (int i = 1; i < (1 << n + 1); i++) { a[i] = 0; }
        for (int i = 1; i < (1 << n); i++) { a[i] = read(); }
        ans.clear(); sum = 0; solve(1, 1);
        printf("%lld\n", sum);
        for (auto u : ans) { printf("%d ", u); }
        printf("\n");
    }
    return 0;
}