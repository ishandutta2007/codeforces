#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> app(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        app[a[i] - 1].push_back(i);
    }
    sort(app.begin(), app.end(), [](auto &a, auto &b){ return a.size() < b.size(); });
    int cur = 0;
    for (int i = 0; i < n; ++i)
    {
        while (cur < app[i].size())
        {
            for (int j = i; j + 1 < n; ++j)
            {
                swap(a[app[j][cur]], a[app[j + 1][cur]]);
            }
            ++cur;
        }
    }
    for (auto &x : a)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}