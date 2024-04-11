#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n;
int a[MAXN];
bool vis[MAXN];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        vis[i] = 0;
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (vis[a[i]])
        {
            ans = i + 1;
            break;
        }
        vis[a[i]] = 1;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}