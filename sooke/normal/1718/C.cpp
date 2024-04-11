#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 2e5 + 5;

int n, q, a[N];
bool npri[N];
std::vector<int> dv;
std::vector<long long> f[N], b[N];

void build(int d, int u, int l, int r) {
    if (l + 1 >= r) { f[d][u] = b[d][l]; return; }
    int mid = l + r >> 1;
    build(d, u << 1, l, mid);
    build(d, u << 1 | 1, mid, r);
    f[d][u] = std::max(f[d][u << 1], f[d][u << 1 | 1]);
}
void modify(int d, int u, int l, int r, int p, long long x) {
    if (l + 1 >= r) { f[d][u] = x; return; }
    int mid = l + r >> 1;
    if (p < mid) {
        modify(d, u << 1, l, mid, p, x);
    } else {
        modify(d, u << 1 | 1, mid, r, p, x);
    }
    f[d][u] = std::max(f[d][u << 1], f[d][u << 1 | 1]);
}
void solve() {
    long long ans = 0;
    for (auto d : dv) {
        ans = std::max(ans, f[d][1] * d);
    }
    printf("%lld\n", ans);
}

int main() {
    for (int i = 2; i <= 200000; i++) {
        for (int j = i + i; j <= 200000; j += i) {
            npri[j] = true;
        }
    }
    for (int T = read(); T; T--) {
        n = read(); q = read();
        for (int i = 0; i < n; i++) {
            a[i] = read();
        }
        dv.clear();
        for (int d = 1; d < n; d++) {
            if (n % d == 0 && !npri[n / d]) {
                dv.push_back(d);
                b[d].clear();
                f[d].clear();
                b[d].resize(d);
                f[d].resize(d * 4);
                for (int i = 0; i < n; i++) {
                    b[d][i % d] += a[i];
                }
                build(d, 1, 0, d);
            }
        }
        solve();
        for (; q; q--) {
            int i = read(), x = read(); i--;
            for (auto d : dv) {
                b[d][i % d] -= a[i];
            }
            a[i] = x;
            for (auto d : dv) {
                b[d][i % d] += a[i];
                modify(d, 1, 0, d, i % d, b[d][i % d]);
            }
            solve();
        }
    }
    return 0;
}