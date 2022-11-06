#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n;
int a[MAXN], b[MAXN];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (n % 2 != 0)
    {
        cout << "NO\n";
        return;
    }
    sort(a, a + n);
    for (int i = 0; i < n / 2; ++i)
    {
        b[i * 2] = a[i];
        b[i * 2 + 1] = a[i + n / 2];
    }
    b[n] = b[0];
    for (int i = 0; i < n; i += 2)
    {
        if (b[i] >= b[i + 1])
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 1; i < n; i += 2)
    {
        if (b[i] <= b[i + 1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
    {
        cout << b[i] << ' ';
    }
    cout << '\n';
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