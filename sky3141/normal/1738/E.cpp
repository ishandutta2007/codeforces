#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9, mod = 998244353;

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

inline LL C(int n, int m)
{
    return fac[n] * facinv[n - m] % mod * facinv[m] % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<LL> s(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int l = 1, r = n;
    LL suml = 0, sumr = 0;
    LL ans = 1;
    while (l <= r)
    {
        if (s[r] == s[l - 1])
        {
            ans = ans * qpow(2, r - l + 2) % mod;
            if (l == 1)
                ans = ans * inv(4) % mod;
            break;
        }
        int cl = l == 1 ? 0 : 1, cr = r == n ? 0 : 1;
        while (a[l] == 0)
        {
            ++l;
            ++cl;
        }
        while (a[r] == 0)
        {
            --r;
            ++cr;
        }
        LL tmp = 0;
        for (int i = 0; i <= min(cl, cr); ++i)
        {
            tmp += C(cl, i) * C(cr, i);
            tmp %= mod;
        }
        ans = ans * tmp % mod;

        suml += a[l];
        ++l;

        while (l <= r && suml != sumr)
        {
            if (suml < sumr)
            {
                suml += a[l];
                ++l;
            }
            else
            {
                sumr += a[r];
                --r;
            }
        }
        if (l > r && suml == sumr)
        {
            ans = ans * 2 % mod;
        }
    }
    cout << ans << '\n';
}

void init()
{
    int n = MAXN - 5;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    facinv[n] = inv(fac[n]);
    for (int i = n - 1; i >= 0; --i)
    {
        facinv[i] = facinv[i + 1] * (i + 1) % mod;
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