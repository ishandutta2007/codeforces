#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9, INF = 1000000000;

struct Frog
{
    int u, dis;
    bool operator<(const Frog &rhs) const
    {
        return dis > rhs.dis;
    }
};

int n, m;
bool vis[MAXN];
priority_queue<Frog> que;
vector<int> e[MAXN];
int d[MAXN];
int dis[MAXN];

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        e[v].push_back(u);
        ++d[u];
    }
    fill(dis + 1, dis + n + 1, INF);
    que.push({n, 0});
    dis[n] = 0;
    while (!que.empty())
    {
        int cur = que.top().u;
        que.pop();
        if (vis[cur])
            continue;
        vis[cur] = true;
        for (auto v : e[cur])
        {
            if (vis[v])
                continue;
            if (dis[cur] + d[v] < dis[v])
            {
                dis[v] = dis[cur] + d[v];
                que.push({v, dis[v]});
            }
            --d[v];
        }
    }
    cout << dis[1] << '\n';
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