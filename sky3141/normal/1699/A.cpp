#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        int a = n / 2;
        cout << a << ' ' << a << ' ' << 0 << '\n';
    }
    else
    {
        cout << "-1\n";
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