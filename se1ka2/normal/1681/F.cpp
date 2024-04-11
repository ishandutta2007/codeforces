#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

template <typename T>
struct Edge
{
    int to;
    T cost;
};

template <typename T>
struct WeightedTree
{
    int n;
    int r;
    int l;
    std::vector<std::vector<Edge<T>>> prit;
    std::vector<std::vector<Edge<T>>> t;
    std::vector<Edge<T>> par;
    std::vector<int> dpt;
    std::vector<Edge<T>> tour;
    std::vector<std::vector<int>> appear_on_tour;
    std::vector<std::vector<int>> anc;

    WeightedTree() {}

    WeightedTree(int n) : n(n)
    {
        prit.resize(n);
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
    }

    void add_edge(int u, int v, T cost)
    {
        prit[u].push_back(Edge<T>{v, cost});
        prit[v].push_back(Edge<T>{u, cost});
    }

    void build(int r_)
    {
        r = r_;
        for (int i = 0; i < n; i++)
            dpt[i] = -1;
        std::queue<int> que;
        par[r].to = -1;
        dpt[r] = 0;
        que.push(r);
        while (que.size())
        {
            int u = que.front();
            que.pop();
            for (Edge<T> &e : prit[u])
            {
                int v = e.to;
                if (dpt[v] == -1)
                {
                    t[u].push_back(e);
                    par[v] = Edge<T>{u, e.cost};
                    dpt[v] = dpt[u] + 1;
                    que.push(v);
                }
            }
        }
    }

    void rebuild(int r_)
    {
        for (int u = 0; u < n; u++)
            t[u].clear();
        build(r_);
    }

    std::vector<int> toposort()
    {
        std::vector<std::pair<int, int>> p(n);
        for (int i = 0; i < n; i++)
            p[i] = std::pair<int, int>(dpt[i], i);
        sort(p.begin(), p.end(), std::greater<std::pair<int, int>>());
        std::vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = p[i].second;
        return res;
    }

    void dfs(int u, int &k)
    {
        for (Edge<T> &e : t[u])
        {
            appear_on_tour[u].push_back(k);
            tour[k++] = e;
            dfs(e.to, k);
        }
        appear_on_tour[u].push_back(k);
        tour[k++] = par[u];
    }

    void build_euler_tour()
    {
        tour.resize(n * 2 - 1);
        appear_on_tour.resize(n);
        int k = 0;
        dfs(0, k);
    }

    void build_lca()
    {
        for (l = 1; l <= n; l++)
        {
            if ((1 << (l - 1)) >= n)
                break;
        }
        anc.resize(l);
        for (int j = 0; j < l; j++)
            anc[j].resize(n);
        for (int i = 0; i < n; i++)
            anc[0][i] = par[i].to;
        for (int j = 1; j < l; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (anc[j - 1][i] == -1)
                    anc[j][i] = -1;
                else
                    anc[j][i] = anc[j - 1][anc[j - 1][i]];
            }
        }
    }

    int lca(int u, int v)
    {
        if (dpt[u] < dpt[v])
            std::swap(u, v);
        int dpt_diff = dpt[u] - dpt[v];
        for (int j = l - 1; j >= 0; j--)
        {
            if ((dpt_diff >> j) & 1)
                u = anc[j][u];
        }
        if (u == v)
            return u;
        for (int j = l - 1; j >= 0; j--)
        {
            if (anc[j][u] != anc[j][v])
            {
                u = anc[j][u];
                v = anc[j][v];
            }
        }
        return anc[0][u];
    }
};

stack<int> st[1000005];
int pa[1000005];
ll s[1000005];
ll dpc[1000005];
ll dpp[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    WeightedTree<int> t(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        u--;
        v--;
        x--;
        t.add_edge(u, v, x);
    }
    t.build(0);
    t.build_euler_tour();
    int u = 0;
    for (Edge<int> e : t.tour)
    {
        if (e.to == -1)
        {
            break;
        }
        if (t.dpt[e.to] > t.dpt[u])
        {
            int v = e.to;
            int w;
            if (st[e.cost].size())
            {
                w = st[e.cost].top();
            }
            else
            {
                w = n + e.cost;
            }
            pa[v] = w;
            st[e.cost].push(v);
        }
        else
        {
            st[e.cost].pop();
        }
        u = e.to;
    }
    vector<int> p = t.toposort();
    for (int u : p)
    {
        s[u] = 1;
        for (Edge<int> e : t.t[u])
        {
            s[u] += s[e.to];
        }
        dpc[pa[u]] += s[u];
    }
    reverse(p.begin(), p.end());
    ll ans = 0;
    for (int u : p)
    {
        if (u == 0)
        {
            continue;
        }
        int r = pa[u];
        dpp[u] = dpc[r] - s[u];
        if (r < n)
        {
            dpp[u] += (n - s[r]);
        }
        ans += (s[u] - dpc[u]) * ((n - s[u]) - dpp[u]);
    }
    cout << ans << "\n";
}