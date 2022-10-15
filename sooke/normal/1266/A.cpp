#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

std::string str;

bool check() {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += str[i] - '0';
    }
    if (sum % 3 != 0) { return false; }
    int pos = -1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') { pos = i; }
    }
    if (pos == -1) { return false; }
    for (int i = 0; i < str.size(); i++) {
        if (i != pos && (str[i] - '0') % 2 == 0) { return true; }
    }
    return false;
}

int main() {
    for (int T = read(); T; T--) {
        std::cin >> str;
        std::cout << (!check() ? "cyan" : "red") << std::endl;
    }
    return 0;
}