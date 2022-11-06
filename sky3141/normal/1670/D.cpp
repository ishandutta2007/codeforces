#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

using LL = long long;

// constexpr int MAXN = 100000 + 9;

int n;

bool check(int x)
{
    LL a = x / 3, b = (x + 1) / 3, c = (x + 2) / 3;
    return n <= 2 * (a * b + b * c + a * c);
}

void solve()
{
    cin >> n;
    int l = 1, r = 100000;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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