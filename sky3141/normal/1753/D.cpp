#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using pii = pair<int, int>;

constexpr int N = 300000 + 9;
constexpr LL INF = 1000000000000000000;

int n, m;
LL p, q;
char a_[N];
vector<pii> e[N];
LL dis[N];
bool vis[N];

inline bool inmap(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

inline char& a(int i, int j)
{
    return a_[i * m + j];
}

inline int idx(int i, int j)
{
    return i * m + j;
}

void addEdge(int fi, int fj, int ti, int tj, int w)
{
    if (inmap(fi, fj) && inmap(ti, tj))
    {
        e[idx(fi, fj)].push_back({idx(ti, tj), w});
    }
}

struct Frog
{
    int u;
    LL w;
    bool operator<(const Frog &rhs) const
    {
        return w > rhs.w;
    }
};

void solve()
{
    cin >> n >> m;
    cin >> p >> q;
    memset(a_, '#', sizeof(a_));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a(i, j);
        }
    }
    priority_queue<Frog> que;
    fill(dis, dis + n * m, INF);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            switch (a(i, j))
            {
            case 'L':
                addEdge(i - 1, j, i, j + 1, p);
                addEdge(i + 1, j, i, j + 1, p);
                addEdge(i, j - 1, i, j + 1, q);
                break;
            
            case 'R':
                addEdge(i - 1, j, i, j - 1, p);
                addEdge(i + 1, j, i, j - 1, p);
                addEdge(i, j + 1, i, j - 1, q);
                break;

            case 'U':
                addEdge(i, j - 1, i + 1, j, p);
                addEdge(i, j + 1, i + 1, j, p);
                addEdge(i - 1, j, i + 1, j, q);
                break;

            case 'D':
                addEdge(i, j - 1, i - 1, j, p);
                addEdge(i, j + 1, i - 1, j, p);
                addEdge(i + 1, j, i - 1, j, q);
                break;
            
            case '.':
                int u = idx(i, j);
                que.push({u, 0});
                dis[u] = 0;
                break;
            }
        }
    }
    while (!que.empty())
    {
        int cur = que.top().u;
        que.pop();
        if (vis[cur])
            continue;
        vis[cur] = true;
        for (auto &[v, w] : e[cur])
        {
            if (dis[cur] + w < dis[v])
            {
                dis[v] = dis[cur] + w;
                que.push({v, dis[v]});
            }
        }
    }
    LL ans = INF;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i < n - 1)
                ans = min(ans, dis[idx(i, j)] + dis[idx(i + 1, j)]);
            if (j < m - 1)
                ans = min(ans, dis[idx(i, j)] + dis[idx(i, j + 1)]);
        }
    }
    cout << (ans < INF ? ans : -1) << '\n';
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