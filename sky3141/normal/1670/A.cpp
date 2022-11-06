#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n;
int a[MAXN];

void solve()
{
    int neg = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] < 0)
            ++neg;
    }
    for (int i = 0; i < neg; ++i)
    {
        if (a[i] > 0)
            a[i] *= -1;
        if (i > 0 && a[i - 1] > a[i])
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i = neg; i < n; ++i)
    {
        if (a[i] < 0)
            a[i] *= -1;
        if (i > neg && a[i - 1] > a[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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