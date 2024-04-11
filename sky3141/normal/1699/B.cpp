#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int a[55][55];

void solve()
{
    int n, m;
    cin >> n >> m;
    // n /= 2;
    // m /= 2;
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < m; j += 2)
        {
            int t = ((i / 2) ^ (j / 2)) & 1;
            if (t)
            {
                a[i][j] = 0;
                a[i][j + 1] = 1;
                a[i + 1][j] = 1;
                a[i + 1][j + 1] = 0;
            }
            else
            {
                a[i][j] = 1;
                a[i][j + 1] = 0;
                a[i + 1][j] = 0;
                a[i + 1][j + 1] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
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