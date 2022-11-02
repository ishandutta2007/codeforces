#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, a, b, p, q;
    scanf("%d %d %d %d %d", &n, &a, &b, &p, &q);
    if (p < q) swap(a, b), swap(p, q);
    ll ans = 0;
    int d = __gcd(a, b);
    ans += 1ll * n / a * p;
    ll e = 1ll * a * b / d;
    ans -= 1ll * n / e * q;
    ans += 1ll * n / b * q;
    printf("%I64d\n", ans);
}