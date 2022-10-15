#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e3 + 5;

int n, ans, a[N];
std::set<int> set;

int main() {
    n = read();
    for (int i = 0; i < n; i++) { a[i] = read(); }
    for (int i = 0; i < n; i++) {
        set.clear();
        for (int j = 0; j < i; j++) { set.insert(a[j]); }
        if (set.size() == i) {
            ans = std::max(ans, i);
            for (int j = n - 1; j >= 0; j--) {
                if (set.count(a[j])) { break; }
                ans = std::max(ans, n - j + i); set.insert(a[j]);
            }
        }
    }
    printf("%d\n", n - ans);
    return 0;
}