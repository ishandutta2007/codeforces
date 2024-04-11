#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

struct Element {
    int i, j, x;
};

bool operator <(const Element &i, const Element &j) {
    return i.x == j.x ? i.j < j.j : i.x < j.x;
}

int n, ans, max, a[N], b[N], c[N][8], p[N];
std::vector<Element> f;

void solve() {
    for (auto t : f) {
        int i = t.i, j = t.j, x = t.x;
        ans = std::min(ans, max - x);
        if (j == 6) { return; }
        p[i]++; max = std::max(max, c[i][p[i]]);
    }
}

int main() {
    for (int i = 1; i <= 6; i++) {
        a[i] = read();
    }
    n = read();
    for (int i = 1; i <= n; i++) {
        b[i] = read();
        for (int j = 1; j <= 6; j++) {
            c[i][j] = b[i] - a[j];
        }
        std::sort(c[i] + 1, c[i] + 6 + 1);
        for (int j = 1; j <= 6; j++) {
            f.push_back((Element) {i, j, c[i][j]});
        }
    }
    std::sort(f.begin(), f.end());
    ans = 2e9;
    for (int i = 1; i <= n; i++) {
        p[i] = 1; max = std::max(max, c[i][1]);
    }
    solve();
    printf("%d\n", ans);
    return 0;
}