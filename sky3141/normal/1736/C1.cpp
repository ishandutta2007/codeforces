#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using pii = pair<int, int>;

constexpr int N = 200000 + 9;

int a[N];

void solve()
{
    int n;
    cin >> n;
    // priority_queue<pii> que;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        // que.push({i - a[i], i});
    }
    int l = 0;
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        l = max(l, i - a[i]);
        ans += i - l;
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