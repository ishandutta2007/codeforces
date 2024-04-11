#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 4000 + 9;

int n;
vector<int> e[MAXN];
int color[MAXN];
int siz[MAXN][2];
int ans;

void dfs(int cur)
{
    siz[cur][0] = siz[cur][1] = 0;
    ++siz[cur][color[cur]];
    for (auto v : e[cur])
    {
        dfs(v);
        siz[cur][0] += siz[v][0];
        siz[cur][1] += siz[v][1];
    }
    if (siz[cur][0] == siz[cur][1])
        ++ans;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        e[i].clear();
    }
    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        e[p].push_back(i);
    }
    string s;
    cin >> s;
    for (int i = 1; i <= n; ++i)
    {
        color[i] = (s[i - 1] == 'W');
    }
    ans = 0;
    dfs(1);
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