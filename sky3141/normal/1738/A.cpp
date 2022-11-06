#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a, b;
    vector<int> t(n);
    for (auto &x : t)
    {
        cin >> x;
    }
    LL ans = 0;
    int mn = 1000000000;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        mn = min(mn, x);
        ans += x;
        if (t[i])
            a.push_back(x);
        else
            b.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    if (a.size() > b.size())
    {
        for (auto x : b)
            ans += x;
        for (int i = 0; i < b.size(); ++i)
            ans += a[i];
    }
    else if (a.size() < b.size())
    {
        for (auto x : a)
            ans += x;
        for (int i = 0; i < a.size(); ++i)
            ans += b[i];
    }
    else
    {
        ans = ans * 2 - mn;
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