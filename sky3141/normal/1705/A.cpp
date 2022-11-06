#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100 + 9;

int n, x;
int a[MAXN * 2];

void solve()
{
    cin >> n >> x;
    for (int i = 0; i < 2 * n; ++i)
        cin >> a[i];
    sort(a, a + 2 * n);
    for (int i = 0; i < n; ++i)
    {
        if (a[n + i] - a[i] < x)
        {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
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