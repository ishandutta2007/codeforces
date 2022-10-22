#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct Edge
{
    int to;
    T cap;
    int rev;
    int id;
};

template <typename T>
struct Flow
{
    int n;
    int source;
    int sink;
    T current_flow;
    std::vector<int> d;
    std::vector<int> nx;
    std::vector<std::vector<Edge<T>>> g;
    std::vector<std::pair<int, int>> epos;

    Flow() {}

    Flow(int n, int source, int sink) : n(n), source(source), sink(sink), current_flow(0)
    {
        d.resize(n);
        nx.resize(n);
        g.resize(n);
    }

    void add_edge(int from, int to, T cap)
    {
        epos.push_back(std::pair<int, int>(from, (int)g[from].size()));
        g[from].push_back((Edge<T>){to, cap, (int)g[to].size(), (int)epos.size() - 1});
        g[to].push_back((Edge<T>){from, 0, (int)g[from].size() - 1, -1});
    }

    T delete_edge(int id)
    {
        Edge<T> &e = g[epos[id].first][epos[id].second];
        Edge<T> &re = g[e.to][e.rev];
        int u = re.to, v = e.to;
        T delete_f = re.cap;
        e.cap = 0;
        re.cap = 0;
        T reverse_f = delete_f - add_flow(u, v, delete_f);
        add_flow(u, source, reverse_f);
        add_flow(sink, v, reverse_f);
        current_flow -= reverse_f;
        return current_flow;
    }

    void bfs(int s)
    {
        fill(d.begin(), d.end(), -1);
        std::queue<int> que;
        d[s] = 0;
        que.push(s);
        while (que.size())
        {
            int u = que.front();
            que.pop();
            for (Edge<T> &e : g[u])
            {
                int v = e.to;
                Edge<T> &re = g[v][e.rev];
                if (re.cap > 0 && d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    que.push(v);
                }
            }
        }
    }

    T dfs(int u, int s, T f)
    {
        if (u == s)
            return f;
        for (int &i = nx[u]; i < (int)g[u].size(); i++)
        {
            Edge<T> &e = g[u][i];
            int v = e.to;
            if (d[v] >= d[u] || e.cap == 0)
                continue;
            if (f == -1)
                f = e.cap;
            else
                f = std::min(f, e.cap);
            T fl = dfs(v, s, f);
            if (fl > 0)
            {
                e.cap -= fl;
                g[e.to][e.rev].cap += fl;
                return fl;
            }
        }
        return 0;
    }

    T add_flow(int r, int s, T max_f)
    {
        T res = 0;
        while (true)
        {
            if (max_f == 0)
                return res;
            bfs(s);
            if (d[r] == -1)
                return res;
            for (int i = 0; i < n; i++)
                nx[i] = 0;
            for (T f; (f = dfs(r, s, max_f)) > 0;)
            {
                res += f;
                if (max_f != -1)
                    max_f -= f;
            }
        }
    }

    T max_flow(T max_f = -1)
    {
        if (max_f != -1)
        {
            max_f -= current_flow;
            if (max_f < 0)
            {
                current_flow -= add_flow(sink, source, -max_f);
                return current_flow;
            }
        }
        current_flow += add_flow(source, sink, max_f);
        return current_flow;
    }

    int get_flow(int id)
    {
        Edge<T> &e = g[epos[id].first][epos[id].second];
        Edge<T> &re = g[e.to][e.rev];
        return re.cap;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int s[10005];
    int a[10005];
    for (int u = 0; u < n; u++)
    {
        cin >> s[u];
    }
    for (int u = 0; u < n; u++)
    {
        cin >> a[u];
    }
    Flow<int> g(n + m + 3, n + m, n + m + 1);
    int d[10005]{0};
    int x[10005], y[10005];
    for (int i = 0; i < m; i++)
    {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        d[x[i]]++;
        d[y[i]]++;
        g.add_edge(i, x[i] + m, 1);
        g.add_edge(i, y[i] + m, 1);
    }
    for (int i = 0; i < m; i++)
    {
        g.add_edge(n + m, i, 1);
    }
    int e = m;
    for (int u = 0; u < n; u++)
    {
        if (s[u])
        {
            if ((a[u] + d[u]) % 2)
            {
                cout << "NO\n";
                return 0;
            }
            int c = (a[u] + d[u]) / 2;
            if (c < 0)
            {
                cout << "NO\n";
                return 0;
            }
            g.add_edge(u + m, n + m + 1, c);
            e -= c;
        }
        else
        {
            g.add_edge(u + m, n + m + 2, m);
        }
    }
    if (e < 0)
    {
        cout << "NO\n";
        return 0;
    }
    g.add_edge(n + m + 2, n + m + 1, e);
    int ans = g.max_flow();
    if (ans < m)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++)
    {
        if (g.get_flow(i * 2))
        {
            cout << y[i] + 1 << " " << x[i] + 1 << "\n";
        }
        else
        {
            cout << x[i] + 1 << " " << y[i] + 1 << "\n";
        }
    }
}