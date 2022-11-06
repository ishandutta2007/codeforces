#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9, mod = 1000000007;

int n;
int a[MAXN], b[MAXN], d[MAXN];
int pa[MAXN], pb[MAXN];
int fa[MAXN];
bool flag[MAXN];
int sz[MAXN];

int getfa(int x)
{
    return fa[x] == x ? x : (fa[x] = getfa(fa[x]));
}

void join(int x, int y)
{
    int fx = getfa(x), fy = getfa(y);
    if (fx != fy)
    {
        fa[fx] = fy;
        sz[fy] += sz[fx];
    }
}

void solve()
{
    cin >> n;
    fill(flag + 1, flag + n + 1, true);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pa[a[i]] = i;
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        pb[b[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        join(i, pb[a[i]]);
        join(i, pa[b[i]]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (d[i])
        {
            flag[getfa(i)] = false;
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (fa[i] == i && sz[i] > 1 && flag[i])
            ans = ans * 2 % mod;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}