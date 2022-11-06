#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9, INF = 1000000000;

int n;
bool a[MAXN][2];
int up[MAXN], down[MAXN];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2; ++i)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; ++j)
            a[j][i] = s[j - 1] == '1';
        a[n + 1][i] = false;
    }
    up[0] = 0;
    down[0] = INF;
    int tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        tot += a[i][0] + a[i][1];
        up[i] = up[i - 1] + a[i][1];
        if (a[i][0] && !a[i + 1][1])
            up[i] = min(up[i], down[i - 1]);
        down[i] = down[i - 1] + a[i][0];
        if (a[i][1] && !a[i + 1][0])
            down[i] = min(down[i], up[i - 1]);
        if (i > 1)
        {
            if (a[i][1] && a[i - 1][0])
                up[i] = min({up[i], up[i - 2] + a[i - 1][1] + 1, down[i - 2] + 1});
            if (a[i][0] && a[i - 1][1])
                down[i] = min({down[i], down[i - 2] + a[i - 1][0] + 1, up[i - 2] + 1});
        }
    }
    int ans = tot - min(up[n], down[n]);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}