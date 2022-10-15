#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, m, num, id[N], deg[N];
std::vector<int> a[5], e[N];
std::pair<long long, long long> hsh[N];
std::map<std::pair<long long, long long>, int> map;
std::set<std::pair<int, int>> set;

bool check() {
    if (num != 3) { return false; }
    for (int i = 0; i < n; i++) { a[id[i]].push_back(i); }
    for (int x = 1; x <= 3; x++) {
        for (int y = x + 1; y <= 3; y++) {
            for (auto u : a[x]) {
                for (auto v : a[y]) {
                    if (set.count({u, v}) == 0) { return false; }
                    deg[u]--; deg[v]--;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] != 0) { return false; }
    }
    return true;
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(); u--; v--;
        e[u].push_back(v); e[v].push_back(u);
        set.insert({u, v}); set.insert({v, u});
        deg[u]++; deg[v]++;
    }
    for (int i = 0; i < n; i++) {
        std::sort(e[i].begin(), e[i].end());
        for (auto x : e[i]) {
            hsh[i].first = (hsh[i].first * 131 + x) % 998244353;
            hsh[i].second = ((hsh[i].second * 131) ^ x) % 998244853;
        }
        if (map[hsh[i]] == 0) {
            map[hsh[i]] = ++num;
        } id[i] = map[hsh[i]];
    }
    if (check()) {
        for (int i = 0; i < n; i++) { printf("%d ", id[i]); }
        printf("\n");
    } else {
        printf("-1\n");
    }
    return 0;
}