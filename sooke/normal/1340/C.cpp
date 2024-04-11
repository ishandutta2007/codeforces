#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e4 + 5, M = 1e3 + 5;

int n, m, kg, kr, a[N], f[N][M];
std::deque<std::pair<int, int>> que;
long long ans = 1e18;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; i++) { a[i] = read(); }
    kg = read(); kr = read();
    std::sort(a + 1, a + m + 1);
    memset(f, 127, sizeof(f));
    f[1][0] = 0; que.push_back({1, 0});
    for (; !que.empty(); ) {
        int i = que.front().first, x = que.front().second; que.pop_front();
        if (i == m) {
            if (x == 0) {
                ans = std::min(ans, 1ll * f[i][x] * (kg + kr) + x - kr);
            } else {
                ans = std::min(ans, 1ll * f[i][x] * (kg + kr) + x);
            }
            continue;
        }
        if (i > 1) {
            int d = a[i] - a[i - 1];
            if (x + d > kg) {
                
            } else if (x + d == kg) {
                if (f[i - 1][0] > f[i][x] + 1) {
                    f[i - 1][0] = f[i][x] + 1;
                    que.push_back({i - 1, 0});
                }
            } else {
                if (f[i - 1][x + d] > f[i][x]) {
                    f[i - 1][x + d] = f[i][x];
                    que.push_front({i - 1, x + d});
                }
            }
        }
        if (i < m) {
            int d = a[i + 1] - a[i];
            if (x + d > kg) {
                
            } else if (x + d == kg) {
                if (f[i + 1][0] > f[i][x] + 1) {
                    f[i + 1][0] = f[i][x] + 1;
                    que.push_back({i + 1, 0});
                }
            } else {
                if (f[i + 1][x + d] > f[i][x]) {
                    f[i + 1][x + d] = f[i][x];
                    que.push_front({i + 1, x + d});
                }
            }
        }
    }
    printf("%lld\n", ans > 1e12 ? -1ll : ans);
    return 0;
}