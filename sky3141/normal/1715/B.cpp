#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    LL n, k, b, s;
    cin >> n >> k >> b >> s;
    LL l = b * k, r = b * k + n * (k - 1);
    LL x = s - l;
    if (l <= s && s <= r)
    {
        for (int i = 0; i < n; ++i)
        {
            LL cur = i == 0 ? b * k : 0;
            LL t = min(x, k - 1);
            cur += t;
            x -= t;
            cout << cur << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << "-1\n";
    }
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