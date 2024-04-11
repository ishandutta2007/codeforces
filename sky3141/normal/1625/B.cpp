#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 150000 + 9, INF = 0x3f3f3f3f;

int a[MAXN];
int pos[MAXN];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = INF;
    for (int i = 0; i < n; ++i)
    {
        ans = min(ans, i - pos[a[i]]);
        pos[a[i]] = i;
    }
    cout << (ans >= INF ? -1 : n - ans) << '\n';
    for (int i = 0; i < n; ++i)
    {
        pos[a[i]] = -INF;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < MAXN; ++i)
    {
        pos[i] = -INF;
    }
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}