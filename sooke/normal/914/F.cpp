#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 100005;

int n, q, m;
std::bitset<maxN> stat, bit[27];
std::string s, t;

int main() {
    std::cin >> s; n = s.size(); s = " " + s;
    for (int i = 1; i <= n; i++) { bit[s[i] - 'a'][i] = 1; }
    for (q = read(); q; q--) {
        int opt = read();
        if (opt == 1) {
            int u = read(); char c; std::cin >> c;
            bit[s[u] - 'a'][u] = 0; s[u] = c; bit[s[u] - 'a'][u] = 1;
        } else {
            int l = read(), r = read();
            std::cin >> t; m = t.size(); t = " " + t;
            r = r - m + 1; if (l > r) { std::cout << 0 << std::endl; continue; }
            stat.set();
            for (int i = 1; i <= m; i++) { stat &= bit[t[i] - 'a'] >> i; }
            std::cout << (stat >> l - 1).count() - (stat >> r).count() << std::endl;
        }
    }
    return 0;
}