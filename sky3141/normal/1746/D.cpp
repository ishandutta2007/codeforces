#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using pll = pair<LL, LL>;

constexpr int N = 200000 + 9;

int n, k;
vector<int> e[N];
int s[N];

pll dfs(int cur, int sum)
{
    if (e[cur].empty())
    {
        return {(LL)sum * s[cur], s[cur]};
    }
    int q = sum / e[cur].size(), r = sum % e[cur].size();
    pll res{0, 0};
    vector<LL> exs;
    for (auto v : e[cur])
    {
        auto t = dfs(v, q);
        res.first += t.first;
        exs.push_back(t.second);
    }
    sort(exs.rbegin(), exs.rend());
    for (int i = 0; i < r; ++i)
    {
        res.first += exs[i];
    }
    res.first += (LL)sum * s[cur];
    res.second += s[cur] + exs[r];
    return res;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        e[i].clear();
    }
    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        e[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }
    auto ans = dfs(1, k).first;
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