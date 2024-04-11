#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    array<vector<string>, 3> a;
    map<string, int> mp;
    for (auto &vec : a)
    {
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            vec.push_back(s);
            ++mp[s];
        }
    }
    array<int, 3> ans{};
    for (int i = 0; i < 3; ++i)
    {
        for (auto &s : a[i])
        {
            if (mp[s] == 1)
            {
                ans[i] += 3;
            }
            else if (mp[s] == 2)
            {
                ans[i] += 1;
            }
        }
    }
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
    
    return 0;
}