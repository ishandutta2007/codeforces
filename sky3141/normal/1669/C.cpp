#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 50 + 9;

int n;
int a[MAXN];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 2; i < n; i += 2)
    {
        if (a[i] % 2 != a[0] % 2)
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 3; i < n; i += 2)
    {
        if (a[i] % 2 != a[1] % 2)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "yeS\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}