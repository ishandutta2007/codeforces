#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9, mod = 1000000007;

int n, m;

LL qpow(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int l, r, x, fin = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> l >> r >> x;
        fin |= x;
    }
    LL ans = fin * qpow(2, n - 1) % mod;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}