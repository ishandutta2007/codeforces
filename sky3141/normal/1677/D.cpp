#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 1000000 + 9, mod = 998244353;

int n, k;
// int a[MAXN];

void solve()
{
    LL ans = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        if (i <= n - k)
        {
            if (x == -1)
            {
                ans = ans * (i + k) % mod;
            }
            else
            {
                if (x > i - 1)
                    ans = 0;
                else if (x == 0)
                    ans = ans * (k + 1) % mod;
            }
        }
        else
        {
            if (x != -1 && x != 0)
                ans = 0;
        }
    }
    for (int i = 1; i <= k; ++i)
        ans = ans * i % mod;
    cout << ans << '\n';
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