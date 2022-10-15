#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, m, q, ans, a[N], max[N], id[N];
std::vector<std::pair<int, int>> d[N];
std::vector<std::pair<double, int>> e;

bool compare(std::pair<double, int> i, std::pair<double, int> j) {
    return i.second < j.second;
}

int main() {
    n = read(); q = read(); m = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); max[i] = a[i];
    }
    for (int i = 0; i < q; i++) {
        int opt = read(), u = read(), x = read(); u--;
        if (opt == 1) {
            if (max[u] < x) { max[u] = x; id[u] = i; }
        } else if (opt == 2) {
            d[u].push_back({x, i});
        } else {
            e.push_back({x, i + q});
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] < max[i]) { d[i].push_back({max[i] - a[i], id[i] - q}); }
        std::sort(d[i].begin(), d[i].end(), std::greater<std::pair<int, int>> ());
        double sum = a[i];
        for (auto j : d[i]) {
            e.push_back({(sum + j.first) / sum, j.second});
            sum += j.first;
        }
    }
    std::sort(e.begin(), e.end(), std::greater<std::pair<double, int>> ());
    ans = std::min(m, (int) e.size());
    std::sort(e.begin(), e.begin() + ans, compare);
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++) {
        printf("%d ", (e[i].second + q) % q + 1);
    }
    return 0;
}