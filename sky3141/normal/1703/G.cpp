#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n, k;
int a[MAXN];

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    LL f[35]{};
    for (int i = n; i >= 1; --i)
    {
        for (int j = 0; j <= 30; ++j)
        {
            f[j] = max(f[j] + (a[i] >> j) - k, f[j + 1] + (a[i] >> (j + 1)));
        }
    }
    cout << f[0] << '\n';
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