#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9, mod = 1000000007;

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

const int inv2 = inv(2);

void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    // LL pre = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i == n)
            ans[i] = qpow(inv2, (i - 1) / 2);
        else
            ans[i] = qpow(inv2, (i + 1) / 2);
        // pre += ans[i];
    }
    // pre %= mod;
    LL sum = 1;
    auto gt = [&](int x){ return x <= n ? ans[x] : 0; };
    for (int i = n; i >= 1; --i)
    {
        sum = (sum + mod * 2 - gt(i * 2) - gt(i * 2 + 1)) % mod;
        ans[i] = ans[i] * sum % mod;
        // sum = (sum - ans[i] + mod) % mod;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << '\n';
    }
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