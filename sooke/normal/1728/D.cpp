#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 2e3 + 5;

int n, f[N][N];
std::string str;

int main() {
    for (int T = read(); T; T--) {
        std::cin >> str;
        n = str.size(); str = " " + str;
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= n + 1; j++) {
                f[i][j] = 1;
            }
        }
        int a, b, c, d;
        for (int len = 2; len <= n; len += 2) {
            for (int i = 1; i <= n; i++) {
                int j = i + len - 1;
                if (j > n) { break; }
                if (str[i] < str[i + 1]) {
                    a = f[i + 2][j] != 1 ? f[i + 2][j] : 0;
                } else if (str[i] > str[i + 1]) {
                    a = f[i + 2][j] != 1 ? f[i + 2][j] : 2;
                } else {
                    a = f[i + 2][j];
                }
                if (str[i] < str[j]) {
                    b = f[i + 1][j - 1] != 1 ? f[i + 1][j - 1] : 0;
                } else if (str[i] > str[j]) {
                    b = f[i + 1][j - 1] != 1 ? f[i + 1][j - 1] : 2;
                } else {
                    b = f[i + 1][j - 1];
                }
                if (str[j] < str[j - 1]) {
                    c = f[i][j - 2] != 1 ? f[i][j - 2] : 0;
                } else if (str[j] > str[j - 1]) {
                    c = f[i][j - 2] != 1 ? f[i][j - 2] : 2;
                } else {
                    c = f[i][j - 2];
                }
                if (str[j] < str[i]) {
                    d = f[i + 1][j - 1] != 1 ? f[i + 1][j - 1] : 0;
                } else if (str[j] > str[i]) {
                    d = f[i + 1][j - 1] != 1 ? f[i + 1][j - 1] : 2;
                } else {
                    d = f[i + 1][j - 1];
                }
                f[i][j] = std::min(std::max(a, b), std::max(c, d));
            }
        }
        if (f[1][n] == 0) { printf("Alice\n"); }
        if (f[1][n] == 1) { printf("Draw\n"); }
        if (f[1][n] == 2) { printf("Bob\n"); }
    }
    return 0;
}