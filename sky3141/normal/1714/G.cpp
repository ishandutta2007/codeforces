#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

struct Edge
{
    int v;
    int a, b;
};

int n;
vector<Edge> e[MAXN];
LL suma[MAXN];
vector<LL> stk;
int ans[MAXN];

void dfs(int cur)
{
    ans[cur] = upper_bound(stk.begin(), stk.end(), suma[cur]) - stk.begin() - 1;
    for (auto &[v, a, b] : e[cur])
    {
        suma[v] = suma[cur] + a;
        stk.push_back(stk.back() + b);
        dfs(v);
        stk.pop_back();
    }
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
        int p, a, b;
        cin >> p >> a >> b;
        e[p].push_back({i, a, b});
    }
    suma[1] = 0;
    stk = {0};
    dfs(1);
    for (int i = 2; i <= n; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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