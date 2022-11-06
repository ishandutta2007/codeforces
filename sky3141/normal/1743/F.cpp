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

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> seg(n);
    for (auto &[l, r] : seg)
    {
        cin >> l >> r;
    }
    reverse(seg.begin(), seg.end());
    int k = 1;
    LL ans = 0;
    set<int> st;
    for (int i = -1; i <= 300001; ++i)
        st.insert(i);
    for (auto &[l, r] : seg)
    {
        auto prevsz = st.size();
        st.erase(st.lower_bound(l), st.upper_bound(r));
        LL extra = prevsz - st.size();
        LL t = k == n ? extra : extra * qpow(3, n - k - 1) * 2 % mod;
        ans += t * qpow(2, k - 1);
        ans %= mod;
        ++k;
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