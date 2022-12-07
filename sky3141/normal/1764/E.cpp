#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> c(n);
    for (auto &[a, b] : c)
    {
        cin >> a >> b;
    }
    if (k <= c[0].first)
    {
        cout << "yes\n";
        return;
    }
    if (k > c[0].first + c[0].second)
    {
        cout << "no\n";
        return;
    }
    int t = k - c[0].second;
    // vector<pair<int, int>> d(c.begin() + 1, c.end());
    c.erase(c.begin());
    sort(c.begin(), c.end(), [](auto &x, auto &y){ return x.first + x.second > y.first + y.second; });
    auto it = c.begin();
    priority_queue<tuple<int, int, int>> que;
    while (true)
    {
        while (it != c.end() && t <= it->first + it->second)
        {
            que.push({it->second - it->first, it->first, it->second});
            ++it;
        }
        if (que.empty())
            break;
        auto [useless, a, b] = que.top();
        que.pop();
        if (t <= a)
        {
            cout << "yes\n";
            return;
        }
        // if (t <= a + b)
        // {
            t -= b;
        // }
    }
    // for (auto &[a, b] : c)
    // {
    //     if (t <= a)
    //     {
    //         cout << "yes\n";
    //         return;
    //     }
    //     if (t <= a + b)
    //     {
    //         t -= b;
    //     }
    // }
    cout << "no\n";
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