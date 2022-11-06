#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = (1 << 17) + 9;

int k, n;
int wv[MAXN], we[MAXN];
int curv;

struct Edge
{
    int v, id;
    Edge *next;
} pool[MAXN * 2], *alloc, *h[MAXN];

void init()
{
    alloc = pool;
    fill(h + 1, h + n + 1, nullptr);
}

void addEdge(int u, int v, int id)
{
    Edge *p = ++alloc, *q = ++alloc;
    p->v = v; p->id = id; p->next = h[u]; h[u] = p;
    q->v = u; q->id = id; q->next = h[v]; h[v] = q;
}

void dfs(int cur, int fa, bool flag)
{
    for (Edge *p = h[cur]; p; p = p->next)
    {
        if (p->v == fa)
            continue;
        ++curv;
        we[p->id] = curv;
        wv[p->v] = curv - n;
        if (flag)
            swap(we[p->id], wv[p->v]);
        dfs(p->v, cur, !flag);
    }
}

void solve()
{
    cin >> k;
    n = 1 << k;
    init();
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, i);
    }
    curv = n;
    wv[1] = curv;
    dfs(1, 0, false);
    cout << "1\n";
    for (int i = 1; i <= n; ++i)
    {
        cout << wv[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n - 1; ++i)
    {
        cout << we[i] << ' ';
    }
    cout << '\n';
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