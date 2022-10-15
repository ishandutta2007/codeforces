#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

int n, m;
std::string s, t;

int main() {
    int T = read();
    for (; T; T--) {
        n = read(); m = read();
        std::cin >> s >> t; s = " " + s; t = " " + t;
        bool ok = false;
        for (int i = n, j = m; i >= 1; ) {
            if (j == 1) { 
                for (int k = 1; k <= i; k++) {
                    if (s[k] == t[j]) { ok = true; break; }
                }
                break;
            }
            if (s[i] == t[j]) {
                i--; j--;
                if (j == 1) {
                    for (int k = 1; k <= i; k++) {
                        if (s[k] == t[j]) { ok = true; break; }
                    }
                    break;
                }
            } else {
                break;
            }
        }
        std::cout << (ok ? "YES" : "NO") << std::endl;
    }
    return 0;
}