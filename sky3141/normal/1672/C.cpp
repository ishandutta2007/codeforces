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
    for (auto &x : a)
    {
        cin >> x;
    }
    int mn = 1000000000, mx = -1;
    for (int i = 0; i + 1 < a.size(); ++i)
    {
        if (a[i] == a[i + 1])
        {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    int ans = mx == -1 ? 0 : max(1, mx - mn - 1);
    if (mn == mx)
        ans = 0;
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