#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int INF = 1000000000;

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
    int n, m;
    cin >> n >> m;
    Graph g(n);
    Graph r(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g.add_edge(u, v);
        r.add_edge(v, u);
    }
    bool b[200005]{0};
    int d[200005];
    int e[200005];
    for(int u = 0; u < n - 1; u++)
    {
        d[u] = INF;
        e[u] = g.g[u].size();
    }
    b[n - 1] = true;
    d[n - 1] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, n - 1));
    while(que.size())
    {
        P p = que.top();
        que.pop();
        int u = p.second;
        b[u] = true;
        if(d[u] < p.first)
        {
            continue;
        }
        for(int v : r.g[u])
        {
            if(b[v])
            {
                continue;
            }
            if(d[u] + e[v] < d[v])
            {
                d[v] = d[u] + e[v];
                que.push(P(d[v], v));
            }
            e[v]--;
        }
    }
    cout << d[0] << endl;
}