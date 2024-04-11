#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 1000 + 9;

int query(int x)
{
    cout << "? " << x + 1 << endl;
    int res;
    cin >> res;
    return res - 1;
}

int fa[MAXN];

int getfa(int x)
{
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}

bool join(int u, int v)
{
    int fu = getfa(u), fv = getfa(v);
    if (fu != fv)
    {
        fa[fu] = fv;
        return true;
    }
    return false;
}

bool vis[MAXN];

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> d(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i].first;
        d[i].second = i;
    }
    sort(d.begin(), d.end(), [](auto &x, auto &y){ return x.first > y.first; });
    for (int i = 0; i < n; ++i)
    {
        fa[i] = i;
    }
    fill(vis, vis + n, false);
    for (auto &[du, u] : d)
    {
        for (int i = 0; i < du && fa[u] == u; ++i)
        {
            int v = query(u);
            if (vis[v])
            {
                join(u, v);
            }
            else
            {
                join(v, u);
                vis[v] = true;
            }
        }
        vis[u] = true;
    }
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i)
    {
        ans[getfa(i)].push_back(i);
    }
    vector<int> col(n);
    for (int i = 0; i < n; ++i)
    {
        for (auto x : ans[i])
        {
            col[x] = i + 1;
        }
    }
    cout << "! ";
    for (int i = 0; i < n; ++i)
    {
        cout << col[i] << ' ';
    }
    cout << endl;
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