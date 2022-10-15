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

const int N = 100005, M = 255;

int n, q, f[M][M][M], g[26][N];
std::string str, a = " ", b = " ", c = " ";

int main() {
    std::cin >> n >> q >> str; str = " " + str;
    for (int i = 0; i < 26; i++) {
        g[i][n + 1] = g[i][n + 2] = n + 1;
    }
    for (int i = n; i; i--) {
        for (int j = 0; j < 26; j++) { g[j][i] = g[j][i + 1]; }
        g[str[i] - 'a'][i] = i;
    }
    for (int i = 0; i <= 252; i++) {
        for (int j = 0; j <= 252; j++) {
            for (int k = 0; k <= 252; k++) { f[i][j][k] = n + 1; }
        }
    }
    f[0][0][0] = 0;
    for (char opt, x, y; q; q--) {
        std::cin >> opt >> x;
        if (opt == '+') {
            std::cin >> y;
            switch (x) {
                case '1': {
                    a += y;
                    for (int i = (int) a.size() - 1; ; ) {
                        for (int j = 0; j < (int) b.size(); j++) {
                            for (int k = 0; k < (int) c.size(); k++) {
                                f[i][j][k] = n + 1;
                                if (i) { f[i][j][k] = std::min(f[i][j][k], g[a[i] - 'a'][f[i - 1][j][k] + 1]); }
                                if (j) { f[i][j][k] = std::min(f[i][j][k], g[b[j] - 'a'][f[i][j - 1][k] + 1]); }
                                if (k) { f[i][j][k] = std::min(f[i][j][k], g[c[k] - 'a'][f[i][j][k - 1] + 1]); }
                            }
                        }
                        break;
                    }
                    break;
                }
                case '2': {
                    b += y;
                    for (int i = 0; i < (int) a.size(); i++) {
                        for (int j = (int) b.size() - 1; ; ) {
                            for (int k = 0; k < (int) c.size(); k++) {
                                f[i][j][k] = n + 1;
                                if (i) { f[i][j][k] = std::min(f[i][j][k], g[a[i] - 'a'][f[i - 1][j][k] + 1]); }
                                if (j) { f[i][j][k] = std::min(f[i][j][k], g[b[j] - 'a'][f[i][j - 1][k] + 1]); }
                                if (k) { f[i][j][k] = std::min(f[i][j][k], g[c[k] - 'a'][f[i][j][k - 1] + 1]); }
                            }
                            break;
                        }
                    }
                    break;
                }
                case '3': {
                    c += y;
                    for (int i = 0; i < (int) a.size(); i++) {
                        for (int j = 0; j < (int) b.size(); j++) {
                            for (int k = (int) c.size() - 1; ; ) {
                                f[i][j][k] = n + 1;
                                if (i) { f[i][j][k] = std::min(f[i][j][k], g[a[i] - 'a'][f[i - 1][j][k] + 1]); }
                                if (j) { f[i][j][k] = std::min(f[i][j][k], g[b[j] - 'a'][f[i][j - 1][k] + 1]); }
                                if (k) { f[i][j][k] = std::min(f[i][j][k], g[c[k] - 'a'][f[i][j][k - 1] + 1]); }
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        } else {
            switch (x) {
                case '1': {
                    a.erase(a.end() - 1, a.end());
                    break;
                }
                case '2': {
                    b.erase(b.end() - 1, b.end());
                    break;
                }
                case '3': {
                    c.erase(c.end() - 1, c.end());
                    break;
                }
            }
        }
        printf("%s\n", f[a.size() - 1][b.size() - 1][c.size() - 1] <= n ? "YES" : "NO");
    }
    return 0;
} // sooke