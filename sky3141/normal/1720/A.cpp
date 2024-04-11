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
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    LL x = a * d, y = b * c;
    if (x > y)
        swap(x, y);
    if (x == y)
    {
        cout << "0\n";
    }
    else if (x == 0 || y % x == 0)
    {
        cout << "1\n";
    }
    else
    {
        cout << "2\n";
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