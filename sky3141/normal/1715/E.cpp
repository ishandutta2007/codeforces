#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;
constexpr LL INF = 1000000000000;

struct Edge
{
    int v, w;
};

struct Frog
{
    int u;
    LL dis;
    bool operator<(const Frog &rhs) const
    {
        return dis > rhs.dis;
    }
};

int n, m, k;
vector<Edge> e[MAXN];
LL dis[MAXN];
bool vis[MAXN];
LL tmpdis[MAXN];
int front, back;
int qu[MAXN];
LL qval[MAXN];

void dijkstra()
{
    priority_queue<Frog> que;
    for (int i = 1; i <= n; ++i)
    {
        que.push({i, dis[i]});
    }
    fill(vis, vis + n + 1, false);
    while (!que.empty())
    {
        int cur = que.top().u;
        que.pop();
        if (vis[cur])
            continue;
        vis[cur] = true;
        for (const auto &[v, w] : e[cur])
        {
            LL newdis = dis[cur] + w;
            if (newdis < dis[v])
            {
                dis[v] = newdis;
                que.push({v, newdis});
            }
        }
    }
}

void plane()
{
    copy(dis, dis + n + 1, tmpdis);
    front = back = 0;
    for (int i = 1; i <= n; ++i)
    {
        LL curv = tmpdis[i] + (LL)i * i;
        while (back - front >= 2 && (curv - qval[back - 1]) * (qu[back-1] - qu[back-2]) <= (qval[back-1] - qval[back-2]) * (i - qu[back-1]))
            --back;
        qu[back] = i;
        qval[back] = curv;
        ++back;
        while (back - front >= 2 && qval[front + 1] - qval[front] <= 2LL * i * (qu[front + 1] - qu[front]))
            ++front;
        dis[i] = min(dis[i], qval[front] + (LL)i * i - 2LL * i * qu[front]);
    }
    front = back = 0;
    for (int i = n; i >= 1; --i)
    {
        LL curv = tmpdis[i] + (LL)i * i;
        while (back - front >= 2 && (qval[back - 1] - curv) * (qu[back-2] - qu[back-1]) >= (qval[back-2] - qval[back-1]) * (qu[back-1] - i))
            --back;
        qu[back] = i;
        qval[back] = curv;
        ++back;
        while (back - front >= 2 && qval[front] - qval[front + 1] >= 2LL * i * (qu[front] - qu[front + 1]))
            ++front;
        dis[i] = min(dis[i], qval[front] + (LL)i * i - 2LL * i * qu[front]);
    }
}

void prans()
{
    for (int i = 1; i <= n; ++i)
    {
        cout << dis[i] << ' ';
    }
    cout << '\n';
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    fill(dis, dis + n + 1, INF);
    dis[1] = 0;
    dijkstra();
    // prans();
    for (int i = 0; i < k; ++i)
    {
        plane();
        // prans();
        dijkstra();
    }
    prans();
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}