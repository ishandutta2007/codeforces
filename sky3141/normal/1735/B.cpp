#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int mn = 1e9;
    for (auto &x : a)
    {
        cin >> x;
        mn = min(mn, x);
    }
    mn = mn * 2 - 1;
    int ans = 0;
    for (auto x : a)
    {
        ans += (x + mn - 1) / mn - 1;
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