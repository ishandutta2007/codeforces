#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9, INF = 1000000000;

int query(int w)
{
    cout << "? " << w << endl;
    int res;
    cin >> res;
    if (res == 0)
        res = INF;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    int l = 1, r = n * 2000 + n - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (query(mid) > 1)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i)
    {
        int w = l / i;
        int h = query(w);
        if (h != INF)
            ans = min(ans, w * h);
    }
    cout << "! " << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}