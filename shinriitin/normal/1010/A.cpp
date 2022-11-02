#include <bits/stdc++.h>

const int max_N = 1000 + 21;

int n, m, a[max_N], b[max_N];

std::vector<int> vec;

bool check(double x) {
    for (auto w : vec) {
        double y = (m + x) / w;
        if (y > x) return false;
        x -= y;
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) scanf("%d", b + i);
    vec.resize(n * 2);
    auto it = vec.begin();
    *it++ = a[1];
    for (int i = 2; i <= n; ++i) *it++ = b[i], *it++ = a[i];
    *it++ = b[1];
    double lo = 0, hi = 2e9, ans = -1;
    while (hi - lo > 1e-9) {
        double mi = (lo + hi) / 2;
        if (check(mi)) ans = hi = mi;
        else lo = mi;
    }
    if (ans > 0) printf("%.10f\n", ans);
    else puts("-1");
    return 0;
}