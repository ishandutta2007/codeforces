#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    if (n & 1)
    {
        cout << "-1\n";
        return;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i += 2)
    {
        if (a[i] == a[i + 1])
        {
            ans.push_back({i + 1, i + 2});
        }
        else
        {
            ans.push_back({i + 1, i + 1});
            ans.push_back({i + 2, i + 2});
        }
    }
    cout << ans.size() << '\n';
    for (auto &[l, r] : ans)
    {
        cout << l << ' ' << r << '\n';
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