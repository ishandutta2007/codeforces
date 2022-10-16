#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const long long inf = 4e18;

const int N = 1e6 + 5;

int n, m;
long long ss, _s, ans, now, f[N], g[N];
std::vector<int> a, b;

inline long long geta(int s) {
    return ss + s * _s;
}
inline long long getb(int t, long long c) {
    return f[t] + g[t] * (c - t);
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < n; i++) {
        int x = read();
        if (x >= 0) {
            a.push_back(x);
        } else {
            b.push_back(x);
        }
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        ss += 1ll * i * a[i]; _s += a[i];
    }
    std::sort(b.begin(), b.end());
    for (int i = (int) b.size() - 1; i >= 0; i--) {
        f[i] = f[i + 1] + 1ll * i * b[i];
        g[i] = g[i + 1] + b[i];
    }
    ans = getb(0, 0) + geta(b.size());
    long long c = 0;
    for (int i = 0, j; i < b.size(); i = j) {
        j = i + m + 1;
        j = std::min(j, (int) b.size());
        long long tmp = now;
        for (int k = i; k < j; k++) {
            tmp += b[k] * c;
            ans = std::max(ans, tmp + getb(k + 1, c + 1) + geta(c + ((int) b.size() - k)));
        }
        for (int k = i; k < j; k++) {
            now += b[k] * c;
        }
        c++;
    }
    ans = std::max(ans, now + geta(c));
    printf("%lld\n", ans);
    return 0;
}