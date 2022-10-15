#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

int n;
std::string s;

int main() {
    for (int tn = read(); tn; tn--) {
        std::cin >> s;
        std::sort(s.begin(), s.end());
        if (s[0] == s[s.size() - 1]) { std::cout << -1 << std::endl; } else { std::cout << s << std::endl; }
    }
    return 0;
} //