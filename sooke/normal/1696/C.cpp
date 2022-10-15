#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

int n, m, k;

std::vector<std::pair<int, long long>> get(std::vector<int> a) {
    int lst = -1;
    long long cnt = 0;
    std::vector<std::pair<int, long long>> f;
    for (auto i : a) {
        int x = i, y = 1;
        while (x % k == 0) {
            x /= k; y *= k;
        }
        if (lst == x) {
            cnt += y;
        } else {
            if (lst != -1) { f.push_back({lst, cnt}); }
            lst = x; cnt = y;
        }
    }
    if (lst != -1) { f.push_back({lst, cnt}); }
    return f;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); k = read();
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = read();
        }
        m = read();
        std::vector<int> b(m);
        for (int i = 0; i < m; i++) {
            b[i] = read();
        }
        printf("%s\n", get(a) == get(b) ? "Yes" : "No");
    }
    return 0;
}