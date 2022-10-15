#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, ans, a[N], b[N];
std::multiset<int> s, t;

int solve(int x) {
    int a = 0;
    for (; x > 0; x /= 10) { a++; }
    return a;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); ans = 0; s.clear(); t.clear();
        for (int i = 0; i < n; i++) {
            a[i] = read(); s.insert(a[i]);
        }
        for (int i = 0; i < n; i++) {
            b[i] = read(); t.insert(b[i]);
        }
        while (true) {
            auto i = s.end(); i--;
            auto j = t.end(); j--;
            if (*i <= 1 && *j <= 1) { break; }
            int x = solve(*i), y = solve(*j);
            if (*i == *j) { s.erase(i); t.erase(j); s.insert(x); t.insert(y); continue; }
            if (*i > *j) {
                s.erase(i); s.insert(x); ans++;
            } else {
                t.erase(j); t.insert(y); ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}