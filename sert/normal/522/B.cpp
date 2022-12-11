#include <cstdio>
#include <iostream>

const int N = 2e5 + 34;

long long n, sum_w;
long long w[N], h[N];
long long mx1, mx2;

int main() {
    ///freopen("a.in", "r", stdin);
    scanf("%I64d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d%I64d", &w[i], &h[i]);
        sum_w += w[i];
        if (h[i] > mx2)
            mx2 = h[i];
        if (mx2 > mx1)
            std::swap(mx1, mx2);
    }
    for (int i = 0; i < n; i++)
        printf("%I64d ", (sum_w - w[i]) * std::min(mx1, mx1 + mx2 - h[i]));
    return 0;
}