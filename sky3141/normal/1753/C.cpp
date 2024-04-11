#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9, mod = 998244353;

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
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    int cnt1 = count(a.begin(), a.end(), 1);
    int kq = 0;
    for (int i = n - cnt1; i < n; ++i)
    {
        if (a[i] == 0)
            ++kq;
    }
    LL ans = 0;
    LL cn2 = (LL)n * (n - 1) / 2 % mod, invcn2 = inv(cn2);
    for (int i = 1; i <= kq; ++i)
    {
        ans += cn2 * inv((LL)i * i % mod);
        ans %= mod;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}