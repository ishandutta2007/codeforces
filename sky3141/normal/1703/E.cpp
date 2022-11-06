#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 100 + 9;

int n;
int a[MAXN][MAXN];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int c[2]{};
            ++c[a[i][j]];
            ++c[a[j][n - 1 - i]];
            ++c[a[n - 1 - i][n - 1 - j]];
            ++c[a[n - 1 - j][i]];
            ans += min(c[0], c[1]);
        }
    }
    ans /= 4;
    cout << ans << '\n';
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