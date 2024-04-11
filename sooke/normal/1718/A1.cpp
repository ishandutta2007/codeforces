#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e5 + 5;

int n, ans, a[N], f[N];

int solve(int l, int r) {
    if (l > r) { return 0; }
    if (l == r) { return 1; }
    int x = 0, res = r - l + 1;
    std::map<int, int> map;
    map[0] = 0; f[l - 1] = 0;
    for (int i = l; i <= r; i++) {
        x ^= a[i]; f[i] = f[i - 1];
        if (map.count(x)) {
            f[i] = std::max(f[i], map[x] + 1);
            map[x] = std::max(map[x], f[i]);
        } else {
            map[x] = f[i];
        }
    }
    return res - f[r];
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 1; i <= n; i++) {
            a[i] = read();
        }
        ans = 0;
        a[n + 1] = 0;
        for (int i = 1, j; i <= n; i = j + 1) {
            j = i;
            for (; a[j] != 0; j++);
            ans += solve(i, j - 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}