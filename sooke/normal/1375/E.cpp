#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e3 + 5;

int n, a[N], b[N], p[N];
std::vector<std::pair<int, int>> ans;

bool cmp(int i, int j) {
    return a[i] < a[j];
}
bool compare(int i, int j) {
    return a[i] == a[j] ? i > j : a[i] > a[j];
}

void solve(int d) {
    if (d == n - 1) { return; }
    std::vector<int> c;
    for (int i = d + 1; i < n; i++) {
        if (b[d] > b[i]) {
            c.push_back(i);
        }
    }
    std::sort(c.begin(), c.end(), compare);
    for (auto i : c) {
        ans.push_back({d, i});
        std::swap(a[d], a[i]);
    }
    solve(d + 1);
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); p[i] = i;
    }
    std::sort(p, p + n, cmp);
    for (int i = 0; i < n; i++) {
        a[p[i]] = b[p[i]] = i;
    }
    solve(0);
    printf("%d\n", ans.size());
    for (auto i : ans) {
        printf("%d %d\n", i.first + 1, i.second + 1);
    }
    return 0;
}