#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (auto &x : a)
    {
        cin >> x;
        if (x != 0)
            ++cnt;
    }
    if (cnt & 1)
    {
        cout << "-1\n";
        return;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i += 1)
    {
        if (a[i] != 0)
        {
            int t = i;
            ++i;
            while (a[i] == 0)
                ++i;
            if (a[t] == a[i])
            {
                if (t < i - 1)
                    ans.push_back({t, i - 2});
                ans.push_back({i - 1, i});
            }
            else
            {
                ans.push_back({t, i - 1});
                ans.push_back({i, i});
            }
        }
        else
        {
            ans.push_back({i, i});
        }
    }
    cout << ans.size() << '\n';
    for (auto &[l, r] : ans)
    {
        cout << l + 1 << ' ' << r + 1 << '\n';
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