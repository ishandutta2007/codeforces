#include <bits/stdc++.h>

using namespace std;
constexpr int GMAX = 1000010;

void solve() {
    int n, m; scanf("%d %d", &n, &m);
    static char crow[GMAX];
    vector<char> compGrid(n * m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", crow);
        for (int j = 0; j < m; ++j) {
            compGrid[m * i + j] = crow[j];
        }
    }
    auto getCell = [&] (int i, int j) {
        return compGrid[m * i + j];
    };
    set<int> blockedCols;
    for (int j = 0; j + 1 < m; ++j) {
        for (int i = 1; i < n; ++i) {
            if (getCell(i, j) == 'X' && getCell(i - 1, j + 1) == 'X') {
                blockedCols.insert(j);
            }
        }
    }
    int q; scanf("%d", &q);
    while (q--) {
        int x1, x2; scanf("%d %d", &x1, &x2);
        --x1; --x2;
        auto eblock = blockedCols.lower_bound(x1);
        if (eblock == blockedCols.end() || *eblock + 1 > x2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

int main() {
    solve();
}