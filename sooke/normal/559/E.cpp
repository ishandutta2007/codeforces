#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 105;

int n, ans, f[N][N][2];
std::pair<int, int> a[N];

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i].first = read(); a[i].second = read();
    }
    a[n++] = {-8e8, 0};
    std::sort(a, a + n);
    for (int i = 0; i < n; i++) {
        for (int u = 0; u <= i; u++) {
            for (int p = 0; p <= 1; p++) {
                ans = std::max(ans, f[i][u][p]);
                int x = a[u].first + p * a[u].second;
                int max = -1e9, v, q;
                for (int j = i + 1; j < n; j++) {
                    for (int o = 0; o <= 1; o++) {
                        int y = a[j].first + o * a[j].second;
                        if (max < y) {
                            max = y; v = j; q = o;
                        }
                        f[j][v][q] = std::max(f[j][v][q], f[i][u][p] + std::min(y - x, a[j].second) + max - y);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}