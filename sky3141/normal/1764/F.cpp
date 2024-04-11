#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 2000 + 9;

int n;
LL f[N][N];
int fa[N];
int root;
vector<int> e[N];
int siz[N];

void dfs(int cur)
{
    siz[cur] = 1;
    for (auto v : e[cur])
    {
        dfs(v);
        siz[cur] += siz[v];
        cout << cur << ' ' << v << ' ' << ((f[cur][cur] - f[cur][v]) / siz[v]) << '\n';
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            LL x;
            cin >> x;
            f[i][j] = f[j][i] = x;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        // vector<pair<int, int>> vec;
        int t = 0;
        LL mx = -100;
        for (int j = 1; j <= n; ++j)
        {
            if (j == i)
                continue;
            if (f[j][j] <= f[i][i] && f[i][j] >= mx)
            {
                mx = f[i][j];
                t = j;
            }
        }
        if (mx >= 0)
        {
            if (f[t][t] == f[i][i])
            {
                if (t < i)
                    fa[i] = t;
            }
            else
                fa[i] = t;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (fa[i])
            e[fa[i]].push_back(i);
        else
            root = i;
    }
    dfs(root);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}