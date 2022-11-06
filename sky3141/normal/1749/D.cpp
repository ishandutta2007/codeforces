#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 300000 + 9, mod = 998244353;

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

inline LL lcm(LL a, LL b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
    LL n, m;
    cin >> n >> m;
    LL mm = m % mod;
    // LL ans = 0, c = 1;
    // for (int i = 0; i < n; ++i)
    // {
    //     c = c * mm % mod;
    //     ans = (ans + c) % mod;
    // }
    LL ans = 0;
    vector<LL> ppm(n + 1);
    ppm[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        ppm[i] = ppm[i - 1] * mm % mod;
        ans += ppm[i];
        ans %= mod;
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     ppm[i] += ppm[i - 1];
    //     ppm[i] %= mod;
    // }
    LL l = 1, t = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (gcd(i, l) == 1)
            l *= i;
        // l = lcm(i, l);
        if (l > m)
            break;
        t *= (m / l) % mod;
        t %= mod;
        // ans -= (m / l) % mod * ppm[n - i];
        ans -= t;
        ans %= mod;
    }
    if (ans < 0)
        ans += mod;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}