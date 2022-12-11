#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll INF = 1000000000000000000;

int main() {
    ll d, k, a, b, t; scanf("%lld %lld %lld %lld %lld", &d, &k, &a, &b, &t);
    auto magic = [&] (ll r) {
        ll base = r * (a * k + t);
        ll rem = d - r * k;
        if (rem <= k) return base + rem * a;
        else return base + k * a + (rem - k) * b;
    };
    ll maxRuns = d / k + (d % k ? 1 : 0);
    ll ans = magic(0);
    for (ll takeTry = max(0LL, maxRuns - 5); takeTry <= maxRuns; ++takeTry) ans = min(ans, magic(takeTry));
    printf("%lld\n", ans);
    return 0;
}