#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

using LL = long long;

using pii = pair<int, int>;

constexpr int MAXN = 100000 + 9;

int n, m;
int bfa[MAXN];
vector<int> e[MAXN];
vector<int> xe[MAXN];
int dfn[MAXN], dfscnt;
int siz[MAXN];
int depth[MAXN];
int a[MAXN];
bool instack[MAXN];
int stack[MAXN];

int getfa(int x)
{
    return bfa[x] == x ? x : (bfa[x] = getfa(bfa[x]));
}

bool join(int x, int y)
{
    int fx = getfa(x), fy = getfa(y);
    if (fx != fy)
    {
        bfa[fx] = fy;
        return true;
    }
    return false;
}

void dfs1(int cur, int fa, int d)
{
    dfn[cur] = ++dfscnt;
    siz[cur] = 1;
    depth[cur] = d;
    for (auto v : e[cur])
    {
        if (v == fa)
            continue;
        dfs1(v, cur, d + 1);
        siz[cur] += siz[v];
    }
}

void add(int pos, int val)
{
    a[dfn[pos]] += val;
    a[dfn[pos] + siz[pos]] -= val;
}

void dfs2(int cur, int fa, int d)
{
    instack[cur] = true;
    stack[d] = cur;
    for (auto v : e[cur])
    {
        if (v == fa)
            continue;
        dfs2(v, cur, d + 1);
    }
    for (auto v : xe[cur])
    {
        if (instack[v])
        {
            add(1, 1);
            add(stack[depth[v] + 1], -1);
            add(cur, 1);
        }
        else
        {
            add(cur, 1);
            add(v, 1);
        }
    }
    instack[cur] = false;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        bfa[i] = i;
    }
    vector<pii> tmpv;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (join(u, v))
        {
            e[u].push_back(v);
            e[v].push_back(u);
        }
        else
        {
            tmpv.push_back({u, v});
        }
    }
    dfs1(1, 0, 0);
    for (auto [u, v] : tmpv)
    {
        if (depth[u] < depth[v])
            swap(u, v);
        xe[u].push_back(v);
        // xe[v].push_back(u);
    }
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; ++i)
    {
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[dfn[i]] == tmpv.size())
        {
            cout << '1';
        }
        else
        {
            cout << '0';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}