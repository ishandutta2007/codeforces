#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n, f[2][N], g[2][N], h[2][N];

std::string str;

int main() {
    std::cin >> str; n = str.size();
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == '0') {
            h[0][i] = std::max(h[0][i], h[0][i + 1] + 1);
            h[0][i] = std::max(h[0][i], h[1][i + 1] + 1);
            h[1][i] = std::max(h[1][i], h[1][i + 1]);
        } else {
            h[0][i] = std::max(h[0][i], h[0][i + 1]);
            h[0][i] = std::max(h[0][i], h[1][i + 1]);
            h[1][i] = std::max(h[1][i], h[1][i + 1] + 1);
        }
        if (str[i] == '0') {
            f[0][i] = std::max(f[0][i], f[0][i + 1] + 1);
            f[0][i] = std::max(f[0][i], f[1][i + 1] + 1);
            f[1][i] = std::max(f[1][i], f[1][i + 1]);
        } else {
            f[0][i] = std::max(f[0][i], f[0][i + 1]);
            f[0][i] = std::max(f[0][i], f[1][i + 1]);
            f[1][i] = std::max(f[1][i], f[1][i + 1] + 1);
        }
        g[0][i] = std::max(g[0][i], f[0][i + 1] + 1);
        g[0][i] = std::max(g[0][i], f[1][i + 1] + 1);
        g[1][i] = std::max(g[1][i], f[1][i + 1]);
        if (std::max(g[0][i], g[1][i]) == std::max(h[0][i], h[1][i])) {
            str[i] = '0'; f[0][i] = g[0][i]; f[1][i] = g[1][i];
        }
    } std::cout << str << std::endl;
    return 0;
}