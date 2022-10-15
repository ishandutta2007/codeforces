#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>

void openFile() {
    freopen("debate.in", "r", stdin);
    freopen("debate.out", "w", stdout);
}

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n, ans;
std::vector<int> a[4];

bool compare(int x, int y) { return x > y; }

int main() {
    // openFile(); // 100 pts.
    n = read();
    for (int i = 0; i < 4; i++) { a[i].push_back(0); }
    for (int i = 0; i < n; i++) {
        int opt = read(), x = read();
        if (opt == 0) { a[0].push_back(x); }
        if (opt == 1) { a[1].push_back(x); }
        if (opt == 10) { a[2].push_back(x); }
        if (opt == 11) { a[3].push_back(x); }
    }
    for (int i = 0; i < 4; i++) {
        std::sort(a[i].begin() + 1, a[i].end(), compare);
        for (int j = 1; j < a[i].size(); j++) { a[i][j] += a[i][j - 1]; }
    }
    if (a[1].size() > a[2].size()) { std::swap(a[1], a[2]); }
    for (int i = 0, j; i < a[0].size(); i++) {
        j = (int) a[3].size() - 1 - i;
        if (j < 0) { break; }
        ans = std::max(ans, a[1].back() + a[3].back() + a[0][i] + a[2][std::min(a[2].size() - 1, a[1].size() - 1 + j)]);
    } printf("%d\n", ans);
    return 0;
}