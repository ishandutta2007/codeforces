#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9, MAXLOG = 30;

struct Edge
{
    int v;
    int x;
};

vector<Edge> e[MAXN];

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> ans(n, (1 << MAXLOG) - 1);
    for (int i = 0; i < q; ++i)
    {
        int u, v, x;
        cin >> u >> v >> x;
        --u; --v;
        ans[u] &= x;
        ans[v] &= x;
        e[u].push_back({v, x});
        e[v].push_back({u, x});
    }
    for (int i = 0; i < n; ++i)
    {
        int t = 0;
        for (const auto &[v, x] : e[i])
        {
            if (v == i)
            {
                t = x;
                break;
            }
            t |= x & ~ans[v];
        }
        ans[i] = t;
    }
    for (const auto &x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
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