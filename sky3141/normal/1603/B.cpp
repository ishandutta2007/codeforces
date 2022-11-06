#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

void solve()
{
    int x, y;
    cin >> x >> y;
    if (x > y)
    {
        cout << y + x << '\n';
    }
    else if (x == y)
    {
        cout << x << '\n';
    }
    else
    {
        cout << (y - y % x / 2) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}