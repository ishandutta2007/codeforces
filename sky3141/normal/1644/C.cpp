#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 5000 + 9, INF = 1000000000;

int n, x;
int a[MAXN], f[MAXN], pre[MAXN];

void solve()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    fill(f, f + n + 1, -INF);
    for (int k = 0; k <= n; ++k)
    {
        int ans = 0;
        copy(f, f + n + 1, pre);
        fill(f, f + n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            f[i] = max(max(f[i - 1] + a[i], pre[i - 1] + x + a[i]), 0);
            ans = max(ans, f[i]);
        }
        cout << ans << ' ';
    }
    cout << endl;
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