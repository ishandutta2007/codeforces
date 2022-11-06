#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
        x = -x;
    }
    for (auto &x : a)
    {
        int b;
        cin >> b;
        x += b;
    }
    multiset<int> neg, pos;
    for (auto &x : a)
    {
        if (x < 0)
            neg.insert(-x);
        else
            pos.insert(x);
    }
    int ans = 0;
    for (auto &x : neg)
    {
        auto it = pos.lower_bound(x);
        if (it != pos.end())
        {
            ++ans;
            pos.erase(it);
        }
    }
    ans += pos.size() / 2;
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