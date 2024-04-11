#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n;
int a[MAXN];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    LL ans = 0;
    bool flag = false;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i])
            flag = true;
        if (flag && a[i] == 0)
            ++ans;
        ans += a[i];
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