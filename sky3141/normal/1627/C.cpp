#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 100000 + 9;

int u[MAXN], v[MAXN], d[MAXN];
int ans[MAXN];

struct Edge
{
    int v;
    int eid;
    Edge *next;
} pool[MAXN * 2], *h[MAXN], *alloc;

void addEdge(int u, int v, int eid)
{
    Edge *p = ++alloc, *q = ++alloc;
    p->v = v; p->eid = eid; p->next = h[u]; h[u] = p;
    q->v = u; q->eid = eid; q->next = h[v]; h[v] = q;
}

void solve()
{
    int n;
    cin >> n;
    alloc = pool;
    for (int i = 1; i <= n; ++i)
    {
        h[i] = nullptr;
        d[i] = 0;
    }
    for (int i = 1; i < n; ++i)
    {
        cin >> u[i] >> v[i];
        ++d[u[i]];
        ++d[v[i]];
        addEdge(u[i], v[i], i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (d[i] > 2)
        {
            cout << "-1\n";
            return ;
        }
    }
    int cur;
    for (int i = 1; i <= n; ++i)
    {
        if (d[i] == 1)
        {
            cur = i;
            break;
        }
    }
    int prev = -1;
    int cans = 2;
    for (int i = 1; i < n; ++i)
    {
        for (Edge *p = h[cur]; p; p = p->next)
        {
            if (p->v != prev)
            {
                prev = cur;
                cur = p->v;
                ans[p->eid] = cans;
                cans = cans == 2 ? 3 : 2;
                break ;
            }
        }
    }
    for (int i = 1; i < n; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}