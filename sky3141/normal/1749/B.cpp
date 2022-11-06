#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    LL ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ans += x;
    }
    int mx = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ans += x;
        mx = max(mx, x);
    }
    ans -= mx;
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