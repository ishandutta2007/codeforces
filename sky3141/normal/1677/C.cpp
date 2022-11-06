#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n;
int a[MAXN], b[MAXN];
bool vis[MAXN];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        b[x] = i;
        vis[i] = false;
    }
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[i] = b[x];
        // cout << a[i] << ' ';
    }
    // cout << endl;
    LL ans = 0, cnt = 0, p = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            int t = 0, cur = i;
            while (!vis[cur])
            {
                vis[cur] = true;
                cur = a[cur];
                ++t;
            }
            int r = t / 2;
            ans += (LL)r * 2 * (cnt + 1) + (LL)2 * r * (r - 1);
            p += t & 1;
            cnt += r * 2;
        }
    }
    ans += (LL)p * cnt;
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