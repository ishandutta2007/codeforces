#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, a, b;

int main() {
    scanf("%d %d %d %d", &n, &k, &a, &b);
    ll mx = 0, mi = 1ll * n * k, m = 1ll * n * k;
    for (int i = 0; i < n; i ++) {
        long long x = abs(__gcd(a + b + 1ll * i * k, m));
        mx = max(mx, x);
        mi = min(mi, x);
        x = abs(__gcd(a - b + 1ll * i * k, m));
        mx = max(mx, x);
        mi = min(mi, x);
    }
    printf("%lld %lld\n", m / mx, m / mi);

    return 0;
}