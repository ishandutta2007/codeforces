#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d, n;
int k, a, b, t;

int main() {
    scanf("%I64d %d %d %d %d", &d, &k, &a, &b, &t);
    if (d <= k) return printf("%I64d\n", d * a), 0;
    if (1ll * a * k + t > 1ll * b * k) {
        return printf("%I64d\n", 1ll * a * k + 1ll * (d - k) * b), 0;
    }
    n = d / k;
    printf("%I64d\n", 1ll * a * k * n + 1ll * (n - 1) * t + min((d % k) * a + t, (d % k) * b));
    return 0;
}