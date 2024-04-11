#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n, k;
vector<int> e[MAXN];
int d[MAXN];
int p[MAXN];
int curans;

int dfs(int cur)
{
    int res = 0;
    d[cur] = 1;
    for (auto v : e[cur])
    {
        res += dfs(v);
        d[cur] = max(d[cur], d[v] + 1);
    }
    if (cur != 1 && p[cur] != 1 && d[cur] == curans)
    {
        ++res;
        d[cur] = 0;
    }
    return res;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        e[i].clear();
    }
    for (int i = 2; i <= n; ++i)
    {
        cin >> p[i];
        e[p[i]].push_back(i);
    }
    int l = 1, r = n - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        curans = mid;
        int t = dfs(1);
        if (t > k)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << '\n';
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