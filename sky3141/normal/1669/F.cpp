#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n;
int a[MAXN];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int sum = 0, l = -1, r = n;
    int ans = 0;
    do
    {
        while (l < r - 1 && sum >= a[r - 1])
        {
            --r;
            sum -= a[r];
        }
        if (sum == 0)
            ans = l + 1 + n - r;
        ++l;
        sum += a[l];
    } while (l < r);
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