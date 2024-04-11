#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    while (!s.empty() && s.back() == '0')
        s.pop_back();
    reverse(s.begin(), s.end());
    if (s.empty())
    {
        cout << "0\n";
        return;
    }
    n = s.size();
    int p0 = find(s.begin(), s.end(), '0') - s.begin();
    vector<int> pos;
    // vector<int> mx(n);
    for (int i = p0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            pos.push_back(i - p0);
        }
    }
    vector<int> ans(pos.size(), 0);
    for (int i = p0 - 1; i >= 0; --i)
    {
        vector<int> cans;
        int j = 0;
        bool flag = false;
        for (auto x : pos)
        {
            if (s[i + x] == '1')
            {
                cans.push_back(1);
                if (!ans[j])
                    flag = true;
            }
            else
            {
                cans.push_back(0);
                if (!flag && ans[j])
                    goto conti;
            }
            ++j;
        }
        ans = cans;
        conti:;
    }
    for (int i = 0; i < pos.size(); ++i)
    {
        if (ans[i])
            s[p0 + pos[i]] = '1';
    }
    cout << s << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}