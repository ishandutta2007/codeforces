#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (auto &x : a)
    {
        cin >> x;
        ++mp[x];
    }
    LL ans1 = 0, ans2 = 0;
    LL cnt = 0;
    for (auto &[k, v] : mp)
    {
        cnt += v;
        ans1 = max(ans1, cnt * (n - cnt));
        ans2 += v / 2;
    }
    LL ans = max(ans1, ans2);
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