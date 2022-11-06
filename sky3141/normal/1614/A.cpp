#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 100 + 9;

int n, l, r, k;
int a[MAXN];

void solve()
{
    cin >> n >> l >> r >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= l && a[i] <= r && k >= a[i])
        {
            k -= a[i];
            ++ans;
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
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}