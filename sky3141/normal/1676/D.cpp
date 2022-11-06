#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200 + 9;

int n, m;
int a[MAXN][MAXN];
int s1[MAXN * 2], s2[MAXN * 2];

void solve()
{
    cin >> n >> m;
    fill(s1, s1 + n + m + 3, 0);
    fill(s2, s2 + n + m + 3, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            s1[i + j] += a[i][j];
            s2[n - i + j] += a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ans = max(ans, s1[i + j] + s2[n - i + j] - a[i][j]);
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}