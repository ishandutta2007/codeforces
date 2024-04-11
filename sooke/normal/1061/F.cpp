#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

const int maxN = 100005;

int n, m, tmp, now, h, f[maxN];
std::string s;

inline bool query(int a, int b, int c) {
    std::cout << "? " << a << " " << b << " " << c << std::endl;
    std::cin >> s;
    if (s == "Yes") { return true; } else { return false; }
}
inline int check(int k, int u, int v) {
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        if (query(u, f[i], v)) { cnt++; }
    }
    return cnt;
}

int main() {
    srand('W' + 'X' + 'W' + 'A' + 'K' + 'I' + 'O' + 'I' + '!' + '!' + '!');
    std::cin >> n >> m; tmp = 1;
    while (true) {
        now += tmp; h++;
        if (now == n) { break; }
        tmp *= m;
    }
    while (true) {
        int u = rand() % n + 1, v = rand() % n + 1, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (query(u, i, v)) { f[++cnt] = i; }
        }
        if (cnt == h + h - 1) {
            for (int i = 1; i <= cnt; i++) {
                if (check(cnt, u, f[i]) == h) { std::cout << "! " << f[i] << std::endl; exit(0); }
            }
        }
    }
    return 0;
}