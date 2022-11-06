#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

LL n, k;
int a[MAXN];
LL sum[MAXN];

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    if (k < n)
    {
        LL mx = 0;
        for (int i = 0; i <= n - k; ++i)
        {
            mx = max(mx, sum[i + k] - sum[i]);
        }
        LL ans = mx + k * (k - 1) / 2;
        cout << ans << '\n';
    }
    else
    {
        LL ans = sum[n] + ((k - 1) + (k - n)) * n / 2;
        cout << ans << '\n';
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