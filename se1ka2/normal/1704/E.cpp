#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

struct Graph
{
    int n;
    std::vector<std::vector<int>> g;

    Graph() {}

    Graph(int n) : n(n)
    {
        g.resize(n);
    }

    void add_edge(int from, int to)
    {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        g[from].push_back(to);
    }

    std::vector<int> bfs(int s)
    {
        assert(0 <= s && s < n);
        std::vector<int> d(n);
        fill(d.begin(), d.end(), -1);
        std::queue<int> que;
        d[s] = 0;
        que.push(s);
        while (que.size())
        {
            int u = que.front();
            que.pop();
            for (int v : g[u])
            {
                if (d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    que.push(v);
                }
            }
        }
        return d;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        ll a[1005];
        for (int u = 0; u < n; u++)
        {
            cin >> a[u];
        }
        Graph g(n), r(n);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            g.add_edge(x, y);
            r.add_edge(y, x);
        }
        int ans = n;
        for (int c = 0; c < n; c++)
        {
            ll b[1005]{0};
            bool f = false;
            for (int u = 0; u < n; u++)
            {
                if (a[u])
                {
                    f = true;
                }
                b[u] = max(0ll, a[u] - 1);
            }
            if (!f)
            {
                ans = c;
                break;
            }
            for (int u = 0; u < n; u++)
            {
                if (a[u])
                {
                    for (int v : g.g[u])
                    {
                        b[v]++;
                    }
                }
            }
            swap(a, b);
        }
        if (ans < n)
        {
            cout << ans << endl;
            continue;
        }
        queue<int> que;
        int d[1005]{0};
        for (int u = 0; u < n; u++)
        {
            d[u] = r.g[u].size();
            if (!d[u])
            {
                que.push(u);
            }
        }
        while (que.size())
        {
            int u = que.front();
            que.pop();
            ans = (a[u] + n) % MOD;
            for (int v : g.g[u])
            {
                a[v] = (a[v] + a[u]) % MOD;
                d[v]--;
                if (!d[v])
                {
                    que.push(v);
                }
            }
        }
        cout << ans << endl;
    }
}