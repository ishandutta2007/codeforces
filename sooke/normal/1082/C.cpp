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
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 200005;

int n, m;
long long max, ans[maxN];
std::vector<int> vec[maxN];

bool cmp(int x, int y) { return x > y; }

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) { int u = read(), x = read(); vec[u].push_back(x); }
    for (int i = 1; i <= m; i++) {
        std::sort(vec[i].begin(), vec[i].end(), cmp);
        if ((int) vec[i].size() && vec[i][0] > 0) { ans[1] += vec[i][0]; }
        for (int j = 1; j < (int) vec[i].size(); j++) {
            vec[i][j] += vec[i][j - 1];
            if (vec[i][j] > 0) { ans[j + 1] += vec[i][j]; }
        }
    }
    for (int i = 1; i <= n; i++) { max = std::max(max, ans[i]); }
    std::cout << max << std::endl;
    return 0;
} ///