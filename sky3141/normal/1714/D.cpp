#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using pii = pair<int, int>;

constexpr int MAXN = 200000 + 9, INF = 1e9;



void solve()
{
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &x : s)
    {
        cin >> x;
    }
    int tn = t.size();
    vector<pii> f(tn + 1, {INF, -1});
    f[tn].first = 0;
    vector<int> can(tn, -1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < tn - (int)s[i].size() + 1; ++j)
        {
            if (s[i] == t.substr(j, s[i].size()))
            {
                if (can[j] == -1 || s[i].size() > s[can[j]].size())
                    can[j] = i;
            }
        }
    }
    for (int i = tn - 1; i >= 0; --i)
    {
        if (can[i] == -1)
            continue;
        int sn = s[can[i]].size();
        for (int j = i + sn; j > i; --j)
        {
            int tmp = f[j].first + 1;
            if (tmp < f[i].first)
            {
                f[i].first = tmp;
                f[i].second = j;
            }
        }
    }
    if (f[0].second == -1)
    {
        cout << "-1\n";
        return;
    }
    cout << f[0].first << '\n';
    for (int i = 0; i < tn; i = f[i].second)
    {
        cout << can[i] + 1 << ' ' << i + 1 << '\n';
    }
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