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
    vector<string> vec(n);
    for (auto &s : vec)
    {
        cin >> s;
    }
    set<string> st(vec.begin(), vec.end());
    string ans(n, '0');
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < vec[i].size(); ++j)
        {
            if (st.contains(vec[i].substr(0, j)) && st.contains(vec[i].substr(j)))
            {
                ans[i] = '1';
                break;
            }
        }
    }
    cout << ans << '\n';
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