#include <bits/stdc++.h>

const int N = 1e6 + 5;

int T, n, m, a[N];
std::string s;

bool check() {
    for (int i = 0; i < n; i++) {
        a[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (a[i % m] == -1) {
                a[i % m] = 0;
            } else if (a[i % m] == 1) {
                return false;
            }
        }
        if (s[i] == '1') {
            if (a[i % m] == -1) {
                a[i % m] = 1;
            } else if (a[i % m] == 0) {
                return false;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (a[i % m] != -1) {
                s[i] = a[i % m] + '0';
            }
        }
    }
    int x = 0, y = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '0') { x++; }
        if (s[i] == '1') { y++; }
    }
    return x <= m / 2 && y <= m / 2;
}

int main() {
    for (std::cin >> T; T; T--) {
        std::cin >> n >> m >> s;
        printf("%s\n", check() ? "YES" : "NO");
    }
    return 0;
}