#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n, c;
    cin >> n >> c;
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++mp[x];
    }
    for (auto &[key, val] : mp)
    {
        ans += min(c, val);
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