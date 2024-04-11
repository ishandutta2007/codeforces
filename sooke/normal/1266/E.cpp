#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, q, a[N], c[N];
long long sum, tmp;
std::map<std::pair<int, int>, int> map;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); sum += a[i]; }
    q = read();
    for (int i = 1; i <= q; i++) {
        int u = read(), w = read(), _v = read(), v;
        if (map[{u, w}] != 0) {
            v = map[{u, w}];
            tmp -= std::min(a[v], c[v]);
            c[v]--;
            tmp += std::min(a[v], c[v]);
            map[{u, w}] = 0;
        }
        if (_v != 0) {
            v = _v;
            tmp -= std::min(a[v], c[v]);
            c[v]++;
            tmp += std::min(a[v], c[v]);
            map[{u, w}] = v;
        }
        printf("%I64d\n", sum - tmp);
    }
    return 0;
}