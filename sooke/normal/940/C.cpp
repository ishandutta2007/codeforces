#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int n, m, cnt, c[256], rnk[256];
std::string s, t;
bool used[256];

int main() {
    std::cin >> n >> m >> s;
    for (int i = 0; i < n; i++) { used[s[i]] = true; }
    for (int i = 0; i < 256; i++) {
        if (used[i]) { c[++cnt] = i; rnk[i] = cnt; }
    }
    if (n < m) {
        std::cout << s;
        for (int i = m; i > n; i--) { putchar(c[1]); }
    } else {
        for (int i = 0; i < m; i++) { t += s[i]; }
        for (int i = m - 1; ~i; i--) {
            if (s[i] != c[cnt]) {
                t[i] = c[rnk[s[i]] + 1];
                for (int j = i + 1; j < m; j++) { t[j] = c[1]; }
                break;
            }
        }
        std::cout << t << std::endl;
    }
    return 0;
} //