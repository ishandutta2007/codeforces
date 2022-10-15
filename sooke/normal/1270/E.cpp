#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e5 + 5;

int n, x[N], y[N];
long long d, bas, dis[N];
std::vector<int> ans;

int main() {
    n = read();
    d = 0; bas = 1;
    for (int i = 0; i < n; i++) {
        x[i] = read(); y[i] = read();
        dis[i] = 1ll * (x[i] - x[0]) * (x[i] - x[0]) + 1ll * (y[i] - y[0]) * (y[i] - y[0]);
        d = std::__gcd(d, dis[i]);
    }
    while (d % 2 == 0) {
        d /= 2; bas *= 2;
    }
    for (int i = 0; i < n; i++) {
        if ((dis[i] / bas) % 2 == 0) {
            ans.push_back(i + 1);
        }
    }
    printf("%d\n", ans.size());
    for (auto i : ans) { printf("%d ", i); }
    return 0;
}