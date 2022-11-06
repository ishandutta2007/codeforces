#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstring>

using namespace std;

using LL = long long;

constexpr int MAXN = 500 + 9;

int n, k;
int a[MAXN][MAXN];
int l[MAXN * MAXN], r[MAXN * MAXN], u[MAXN * MAXN], d[MAXN * MAXN];
int sum[MAXN][MAXN];

void solve()
{
    cin >> n >> k;
    int cn = n * n;
    for (int i = 1; i <= cn; ++i)
    {
        l[i] = u[i] = n + 1;
        r[i] = d[i] = 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            a[i][j] = x;
            if (r[x] == 0)
                ++cnt;
            l[x] = min(l[x], j);
            r[x] = max(r[x], j);
            u[x] = min(u[x], i);
            d[x] = max(d[x], i);
        }
    }
    if (k >= cnt)
    {
        cout << k - cnt << '\n';
        return;
    }
    for (int len = 1; len <= n; ++len)
    {
        memset(sum, 0, sizeof(sum));
        for (int c = 1; c <= cn; ++c)
        {
            if (r[c] == 0)
                continue;
            int tl = max(r[c] - len + 1, 1), tr = l[c] + 1;
            int tu = max(d[c] - len + 1, 1), td = u[c] + 1;
            if (tl < tr && tu < td)
            {
                ++sum[tu][tl];
                --sum[tu][tr];
                --sum[td][tl];
                ++sum[td][tr];
            }
        }
        for (int i = 1; i <= n - len + 1; ++i)
        {
            for (int j = 1; j <= n - len + 1; ++j)
            {
                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
                int t = cnt - sum[i][j];
                if (t == k || t == k - 1)
                {
                    cout << "1\n";
                    return;
                }
            }
        }
    }
    cout << "2\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}