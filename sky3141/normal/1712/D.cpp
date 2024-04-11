#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

using LL = long long;
using pii = pair<int, int>;

constexpr int MAXN = 100000 + 9, INF = 1000000000;

int n, k;
int a[MAXN];

void solve()
{
    cin >> n >> k;
    priority_queue<pii, vector<pii>, greater<pii>> que;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        que.push({a[i], i});
    }
    while (k > 1)
    {
        int pos = que.top().second;
        que.pop();
        a[pos] = INF;
        --k;
    }
    int mn = que.top().first;
    int ans = -INF;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, a[i]);
    }
    ans = min(ans, mn * 2);
    a[que.top().second] = INF;
    mn = INF;
    for (int i = 1; i <= n; ++i)
    {
        mn = min(mn, a[i]);
    }
    int ans2 = -INF;
    for (int i = 1; i <= n - 1; ++i)
    {
        ans2 = max(ans2, min(a[i], a[i + 1]));
    }
    ans2 = min(ans2, mn * 2);
    ans = max(ans, ans2);
    cout << ans << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}