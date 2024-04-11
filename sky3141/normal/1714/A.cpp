#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n, h, m;
    cin >> n >> h >> m;
    int t = h * 60 + m;
    int ans = 100000;
    for (int i = 0; i < n; ++i)
    {
        cin >> h >> m;
        int t2 = h * 60 + m;
        ans = min(ans, (t2 + 1440 - t) % 1440);
    }
    cout << ans / 60 << ' ' << ans % 60 << '\n';
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