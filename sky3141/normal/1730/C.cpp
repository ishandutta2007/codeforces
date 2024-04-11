#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    string s;
    cin >> s;
    string t;
    int cnt[10]{};
    for (char c : s)
    {
        while (!t.empty() && t.back() > c)
        {
            ++cnt[min(t.back() - '0' + 1, 9)];
            t.pop_back();
        }
        t.push_back(c);
    }
    for (auto c : t)
    {
        ++cnt[c - '0'];
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < cnt[i]; ++j)
        {
            cout << i;
        }
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