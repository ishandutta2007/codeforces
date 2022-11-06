#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 60 + 9, mod = 998244353;

LL a[MAXN], b[MAXN], c[MAXN];
LL fac[MAXN], facinv[MAXN];

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

void solve()
{
    int n;
    cin >> n;
    cout << a[n] << ' ' << b[n] << ' ' << c[n] << '\n';
}

inline LL C(int n, int m)
{
    if (n < m) return 0;
    return fac[n] * facinv[n - m] % mod * facinv[m] % mod;
}

void init()
{
    a[0] = b[0] = 0;
    c[0] = 1;
    fac[0] = 1;
    int tn = MAXN - 5;
    for (int i = 1; i <= tn; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    facinv[tn] = inv(fac[tn]);
    for (int i = tn - 1; i >= 0; --i)
    {
        facinv[i] = facinv[i + 1] * (i + 1) % mod;
    }
    for (int i = 2; i <= 60; i += 2)
    {
        a[i] = C(i - 1, i / 2);
        b[i] = C(i - 2, i / 2);
        c[i] = c[i - 2];
        a[i] += b[i - 2];
        b[i] += a[i - 2];
        a[i] %= mod;
        b[i] %= mod;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    init();
    while (T--)
    {
        solve();
    }
}