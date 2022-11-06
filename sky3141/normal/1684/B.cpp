#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int z = c, y = c + b, x = c + b + a;
    cout << x << ' ' << y << ' ' << z << '\n';
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