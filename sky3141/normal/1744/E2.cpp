#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;

LL a, b, c, d;

void chai(int a, map<int, int> &mp)
{
    for (int i = 2; i * i <= a; ++i)
    {
        while (a % i == 0)
        {
            ++mp[i];
            a /= i;
        }
    }
    if (a > 1)
        ++mp[a];
}

pair<LL, LL> dfs(LL cur, const map<int, int> &mp, map<int, int>::iterator it)
{
    if (it == mp.end())
    {
        LL ra = cur, rb = a * b / cur;
        ra = c / ra * ra;
        rb = d / rb * rb;
        if (ra > a && rb > b)
        {
            return {ra, rb};
        }
        return {-1, -1};
    }
    for (int i = 0; i <= it->second; ++i)
    {
        auto res = dfs(cur, mp, next(it));
        if (res.first != -1)
            return res;
        cur *= it->first;
    }
    return {-1, -1};
}

void solve()
{
    // int a, b, c, d;
    cin >> a >> b >> c >> d;
    map<int, int> mp;
    chai(a, mp);
    chai(b, mp);
    auto ans = dfs(1, mp, mp.begin());
    cout << ans.first << ' ' << ans.second << '\n';
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