#include <cstdio>
#include <algorithm>

int n, m, ln, rn, lm, rm, lb, rb, ll = 2e9, ans;

int main() {
    scanf("%d%d", &n, &m);
    for (int l = 1, r; l <= n + m; l = r + 1) {
        r = 2e9;
        if (n / l) { r = std::min(r, n / (n / l)); }
        if (m / l) { r = std::min(r, m / (m / l)); }
        ln = (n - 1) / (r + 1); rn = n / r;
        lm = (m - 1) / (r + 1); rm = m / r;
        lb = ln + lm + 1; rb = rn + rm;
        rb = std::min(rb, ll);
        if (ln < rn && lm < rm) { ans += std::max(0, rb - lb); }
        ll = std::min(ll, lb);
    } printf("%d\n", ans);
    return 0;
}