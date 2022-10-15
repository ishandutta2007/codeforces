#include <bits/stdc++.h>

int n, m, x;
std::string str;

inline int get(char c) {
    if (c == '?') { return 9; }
    return (c & 15) * 2;
}

int main() {
    std::cin >> n >> str; m = n / 2;
    for (int i = 0; i < m; i++) {
        x += get(str[i]);
    }
    for (int i = m; i < n; i++) {
        x -= get(str[i]);
    } printf("%s\n", x == 0 ? "Bicarp" : "Monocarp");
    return 0;
}