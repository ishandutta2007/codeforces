#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9, mod = 1000000007;

int n;
int a[MAXN];

void solve()
{
    cin >> n;
    LL ans = 1;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        a[t] = i;
    }
    int l = a[0], r = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (l < a[i] && a[i] < r)
        {
            ans *= (r - l + 1) - i;
            ans %= mod;
        }
        else
        {
            l = min(l, a[i]);
            r = max(r, a[i]);
        }
    }
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