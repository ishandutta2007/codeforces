#include <bits/stdc++.h>
using namespace std;

constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}
// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
 
    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;
 
    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b
 
        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b
 
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}
// (rem, mod)
std::pair<long long, long long> crt(const std::vector<long long>& r,
                                    const std::vector<long long>& m) {
    assert(r.size() == m.size());
    int n = int(r.size());
    // Contracts: 0 <= r0 < m0
    long long r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= m[i]);
        long long r1 = safe_mod(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)
 
        // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));
        // r2 % m0 = r0
        // r2 % m1 = r1
        // -> (r0 + x*m0) % m1 = r1
        // -> x*u0*g = r1-r0 (mod u1*g) (u0*g = m0, u1*g = m1)
        // -> x = (r1 - r0) / g * inv(u0) (mod u1)
 
        // im = inv(u0) (mod u1) (0 <= im < u1)
        long long g, im;
        std::tie(g, im) = inv_gcd(m0, m1);
 
        long long u1 = (m1 / g);
        // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)
        if ((r1 - r0) % g) return {0, 0};
 
        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)
        long long x = (r1 - r0) / g % u1 * im % u1;
 
        // |r0| + |m0 * x|
        // < m0 + m0 * (u1 - 1)
        // = m0 + m0 * m1 / g - m0
        // = lcm(m0, m1)
        r0 += x * m0;
        m0 *= u1;  // -> lcm(m0, m1)
        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}

using ll = long long;

int main() {
    int n, m; ll k; scanf("%d %d %lld", &n, &m, &k);
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) --a[i];
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < m; ++i) --b[i];
    int maxColor = 2 * max(n, m);
    vector<int> posInA(maxColor, -1), posInB(maxColor, -1);
    for (int i = 0; i < n; ++i) posInA[a[i]] = i;
    for (int i = 0; i < m; ++i) posInB[b[i]] = i;
    vector<pair<ll, ll>> crtReturns(maxColor, {0, 0});
    for (int c = 0; c < maxColor; ++c) {
        if (posInA[c] != -1 && posInB[c] != -1) {
            crtReturns[c] = crt(vector<ll>{posInA[c], posInB[c]}, vector<ll>{n, m});
        }
    }

    auto angeryCoeff = [&] (ll until) {
        ll ans = until;
        for (int i = 0; i < maxColor; ++i) {
            auto [val, period] = crtReturns[i];
            if (val == 0 && period == 0) continue;
            if (until < val) continue;
//            printf("until color %d score %lld %lld\n", i, val, period);
            ans -= (until - val) / period + ((until - val) % period == 0 ? 0 : 1);
        }
//        printf("until %lld ans %lld\n", until, ans);
        return ans;
    };

    ll lo = 1, hi = 1000000000000000000;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (angeryCoeff(mid) >= k) hi = mid;
        else lo = mid + 1;
    }
    printf("%lld\n", lo);
    return 0;
}