#include <bits/stdc++.h>

int n, m;
std::vector<std::pair<int, int>> ans;

void solve(int sgn) {
    for (int len = 1; len < n; len *= 2) {
        for (int i = 0; i < n; i += len * 2) {
            for (int j = 0; j < len; j++) {
                int x = i + j, y = i + j + len;
                if (x > m || y > m) { continue; }
                if (sgn == 0) { ans.push_back({x + 1, y + 1}); }
                if (sgn == 1) { ans.push_back({m - x, m - y}); }
            }
        }
    }
}

int main() {
    scanf("%d", &m); n = 1;
    while (n < m) { n *= 2; } n /= 2;
    solve(0); solve(1);
    printf("%d\n", ans.size());
    for (auto i : ans) {
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}