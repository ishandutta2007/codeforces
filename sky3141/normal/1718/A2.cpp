#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n;
int a[MAXN];
int sum[MAXN];
int dp[MAXN];

void solve()
{
    cin >> n;
    map<int, int> lst{{0, 0}};
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
        if (a[i] == 0)
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            auto it = lst.find(sum[i]);
            dp[i] = dp[i - 1] + 1;
            if (it != lst.end())
                dp[i] = min(dp[i], dp[it->second] + i - it->second - 1);
        }
        lst[sum[i]] = i;
    }
    cout << dp[n] << '\n';
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