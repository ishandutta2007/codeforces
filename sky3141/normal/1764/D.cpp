#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 5000 + 9;

// #define int LL

int mod;
LL fac[N];
LL facinv[N];

LL qpow(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

inline LL inv(LL x)
{
    return qpow(x, mod - 2);
}

inline LL A(LL n, LL k)
{
    return fac[n] * facinv[k] % mod;
}

inline LL C(LL n, LL m)
{
    return fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}

void solve()
{
    int n;
    cin >> n >> mod;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    for (int i = 0; i <= n; ++i)
    {
        facinv[i] = inv(fac[i]);
    }
    LL ans = 0;
    for (int i = 0; i * 2 < n; ++i)
    {
        LL t = 0;
        for (int j = 1; j < n - i; ++j)
        {
            if (j * 2 <= n && (n - (i + j)) * 2 <= n)
            {
                ++t;
            }
        }
        if (i == 0)
        {
            ans += t * n * fac[n - 2];
            ans %= mod;
            continue;
        }
        for (int k = 0; k < i; ++k)
        {
            LL tmp = n - i - 2;
            // ans += n * fac[n - i - 2] % mod * t % mod * A(i - 1, k) % mod * C(n - i - 2 + k, k);
            ans += (LL)n * t % mod * C(i - 1, k) % mod * fac[tmp + k] % mod;
            ans %= mod;
        }
        // ans += n * (i == 0 ? fac[n - 2] : fac[n - 3]);
        // ans %= mod;
    }
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