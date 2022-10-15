#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e5 + 5;

int n, m, ans, dp[N];

std::vector<std::pair<int, int>> f, g;

bool compare0(std::pair<int, int> u, std::pair<int, int> v) {
    return u.first < v.first;
}
bool compare1(std::pair<int, int> u, std::pair<int, int> v) {
    return u.first + u.second > v.first + v.second;
}


int main() {
    n = read(); m = read();
    for (int i = 0; i < n; i++) {
        int x = read(), y = read();
        if (y >= 0) { f.push_back({x, y}); }
        else { g.push_back({x, y}); }
    }
    std::sort(f.begin(), f.end(), compare0);
    std::sort(g.begin(), g.end(), compare1);
    for (int i = 0; i < f.size(); i++) {
        if (f[i].first <= m) {
            m += f[i].second; ans++;
        }
    }
    for (int i = 0; i < g.size(); i++) {
        for (int j = g[i].first; j <= m; j++) {
            if (j + g[i].second >= 0) {
                dp[j + g[i].second] = std::max(dp[j + g[i].second], dp[j] + 1);
            }
        }
    }
    printf("%d\n", ans + *std::max_element(dp, dp + m + 1));
    return 0;
}