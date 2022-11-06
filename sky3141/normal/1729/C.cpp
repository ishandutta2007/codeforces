#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cost = abs(s[0] - s.back());
    vector<pair<char, int>> vec;
    for (int i = 0; i < n; ++i)
    {
        vec.push_back({s[i], i});
    }
    if (s[0] > s.back())
    {
        for (auto &[c, v] : vec)
        {
            c = -c;
        }
    }
    sort(vec.begin(), vec.end());
    bool flag = false;
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        if (vec[i].second == 0)
        {
            flag = true;
        }
        if (flag)
            ans.push_back(vec[i].second + 1);
        if (vec[i].second == n - 1)
        {
            break;
        }
    }
    cout << cost << ' ' << ans.size() << '\n';
    for (auto &x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
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