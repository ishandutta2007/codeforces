#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n, k;
// int a[MAXN];

void solve()
{
    int ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        if (i <= k && x > k)
            ++ans;
    }
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