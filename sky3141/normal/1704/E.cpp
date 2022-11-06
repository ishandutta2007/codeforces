#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

using LL = long long;

constexpr int MAXN = 1000 + 9, mod = 998244353;

int a[MAXN];
vector<int> e[MAXN], te[MAXN];
int ind[MAXN];
int mul[MAXN];
bool flag[MAXN];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        e[i].clear();
        te[i].clear();
        ind[i] = 0;
        mul[i] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        e[v].push_back(u);
        te[u].push_back(v);
        ++ind[u];
    }
    int start;
    for (int i = 1; i <= n; ++i)
    {
        if (ind[i] == 0)
        {
            start = i;
            break;
        }
    }
    queue<int> que;
    que.push(start);
    mul[start] = 1;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        for (auto v : e[cur])
        {
            mul[v] += mul[cur];
            mul[v] %= mod;
            --ind[v];
            if (ind[v] == 0)
            {
                que.push(v);
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += (LL)a[i] * mul[i];
        ans %= mod;
    }
    for (int i = 0; i < n; ++i)
    {
        bool zero = true;
        for (int j = 1; j <= n; ++j)
        {
            if (a[j])
            {
                zero = false;
                break;
            }
        }
        if (zero)
            break;
        if (a[start] == 0)
            ++ans;
        for (int j = 1; j <= n; ++j)
        {
            flag[j] = a[j] > 0;
        }
        for (int j = 1; j <= n; ++j)
        {
            if (flag[j])
            {
                for (auto v : te[j])
                {
                    ++a[v];
                }
                --a[j];
            }
        }
    }
    ans %= mod;
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