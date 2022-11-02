#include <bits/stdc++.h>

using LL = long long;

const int max_N = (int) 1e5 + 21;

int n, q;

LL s[max_N], sum[max_N], ss[max_N];

LL solve(LL len) {
    int it = std::upper_bound(ss + 1, ss + n, len) - ss - 1;
    return sum[it] + LL(n - it) * len;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", s + i);
    }
    std::sort(s + 1, s + 1 + n);
    for (int i = 1; i < n; ++i) {
        ss[i] = s[i + 1] - s[i];
    }
    std::sort(ss + 1, ss + n);
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + ss[i];
    }
    scanf("%d", &q);
    LL ql, qr;
    for (int i = 1; i <= q; ++i) {
        scanf("%lld%lld", &ql, &qr);
        printf("%lld%c", solve(qr - ql + 1), " \n"[i == q]);
    }
}