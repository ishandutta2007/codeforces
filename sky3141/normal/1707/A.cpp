#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n, q;
int a[MAXN];
int ans[MAXN];

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int cur = 0;
    for (int i = n; i >= 1; --i)
    {
        if (cur < a[i])
        {
            if (cur < q)
            {
                ++cur;
                ans[i] = 1;
            }
            else
            {
                ans[i] = 0;
            }
        }
        else
        {
            ans[i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i];
    }
    cout << '\n';
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