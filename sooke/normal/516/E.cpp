#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

void exgcd(int a, int b, int &x, int &y) {
    if (b == 0) { x = 1; y = 0; return; }
    exgcd(b, a % b, y, x);
    y -= x * (a / b);
}
int findInv(int x, int mod) {
    int res, tmp;
    exgcd(x, mod, res, tmp);
    return (res % mod + mod) % mod;
}

const int N = 2e5 + 5;

int n, m, g, gn, gm, invn, invm, na, nb, ra, rb;
std::vector<int> a[N], b[N];
long long ans;

bool check(std::vector<std::pair<int, int>> f, int r, int n) {
    if (r >= n) { return true; }
    std::sort(f.begin(), f.end());
    for (auto i : f) {
        if (i.first > r) { return false; }
        r = std::max(r, i.second);
    }
    return r >= n;
}

int main() {
    n = read(); m = read();
    g = std::__gcd(n, m);
    if (g > 2e5) { printf("-1\n"); return 0; }
    gn = n / g; gm = m / g;
    invn = findInv(gn, gm);
    invm = findInv(gm, gn);
    na = read();
    for (int i = 0; i < na; i++) {
        int x = read();
        a[x % g].push_back(x / g);
    }
    nb = read();
    for (int i = 0; i < nb; i++) {
        int x = read();
        b[x % g].push_back(x / g);
    }
    for (int d = 0; d < g; d++) {
        if (a[d].empty() && b[d].empty()) { printf("-1\n"); return 0; }
        if (a[d].size() == gn && b[d].size() == gm) { continue; }
        long long res;
        int k, y;
        for (long long l = 0, r = (gn + 1ll) * (gm + 1), mid; l <= r; ) {
            mid = (l + r) / 2;
            std::vector<std::pair<int, int>> fa, fb;
            ra = rb = 0;
            for (auto x : a[d]) {
                fa.push_back({1ll * x * invm % gn, 1ll * x * invm % gn + 1});
                if (mid < x) { continue; }
                k = (mid - x) / gm;
                y = 1ll * x * invm % gn;
                fa.push_back({y, y + k + 1});
                ra = std::max(ra, y + k - gn + 1);
                k = (mid - x) / gn;
                y = 1ll * x * invn % gm;
                fb.push_back({y, y + k + 1});
                rb = std::max(rb, y + k - gm + 1);
            }
            for (auto x : b[d]) {
                fb.push_back({1ll * x * invn % gm, 1ll * x * invn % gm + 1});
                if (mid < x) { continue; }
                k = (mid - x) / gm;
                y = 1ll * x * invm % gn;
                fa.push_back({y, y + k + 1});
                ra = std::max(ra, y + k - gn + 1);
                k = (mid - x) / gn;
                y = 1ll * x * invn % gm;
                fb.push_back({y, y + k + 1});
                rb = std::max(rb, y + k - gm + 1);
            }
            if (check(fa, ra, gn) && check(fb, rb, gm)) {
                r = mid - 1; res = mid;
            } else {
                l = mid + 1;
            }
        }
        ans = std::max(ans, res * g + d);
    }
    printf("%lld\n", ans);
    return 0;
} //