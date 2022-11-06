#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<array<int, 2>> sum(n);
    for (int i = 1; i < n; ++i)
    {
        sum[i] = sum[i - 1];
        if (s[i] == s[i - 1])
        {
            ++sum[i][s[i] - '0'];
        }
    }
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l; --r;
        int ans = max(sum[r][0] - sum[l][0], sum[r][1] - sum[l][1]) + 1;
        cout << ans << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}