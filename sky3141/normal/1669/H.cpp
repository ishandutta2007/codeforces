#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    int ans = 0;
    for (int i = 30; i >= 0; --i)
    {
        int cnt = 0;
        for (auto &x : a)
        {
            if (!(x & (1 << i)))
                ++cnt;
        }
        if (cnt <= k)
        {
            ans |= 1 << i;
            k -= cnt;
        }
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