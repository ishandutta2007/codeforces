#include <algorithm>
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
typedef long long ll;

struct Tree
{
    int n;
    int r;
    int l;
    int c;
    bool is_built;
    bool is_built_lca;
    std::vector<std::vector<int>> prit;
    std::vector<std::vector<int>> t;
    std::vector<int> par;
    std::vector<int> dpt;
    std::vector<int> s;
    std::vector<int> tour;
    std::vector<std::vector<int>> appear_on_tour;
    std::vector<std::vector<int>> anc;

    Tree() {}

    Tree(int n) : n(n)
    {
        c = 0;
        prit.resize(n);
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
        s.resize(n);
    }

    void add_edge(int u, int v)
    {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        prit[u].push_back(v);
        prit[v].push_back(u);
        c++;
        assert(c < n);
    }

    void build_sub(int u, int k)
    {
        dpt[u] = k;
        s[u] = 1;
        for (int v : prit[u])
        {
            if (par[u] == v)
            {
                continue;
            }
            t[u].push_back(v);
            par[v] = u;
            build_sub(v, k + 1);
            s[u] += s[v];
        }
    }

    void build(int r_)
    {
        assert(c == n - 1);
        assert(0 <= r_ && r_ < n);
        r = r_;
        for (int u = 0; u < n; u++)
        {
            par[u] = -1;
        }
        build_sub(r, 0);
        is_built = true;
    }

    void rebuild(int r_)
    {
        for (int u = 0; u < n; u++)
        {
            t[u].clear();
        }
        build(r_);
    }

    std::vector<int> toposort(bool is_reverse = true)
    {
        assert(is_built);
        std::vector<int> p;
        std::queue<int> que;
        que.push(r);
        while (que.size())
        {
            int u = que.front();
            que.pop();
            p.push_back(u);
            for (int v : t[u])
            {
                que.push(v);
            }
        }
        if (is_reverse)
        {
            std::reverse(p.begin(), p.end());
        }
        return p;
    }

    void build_euler_tour_sub(int u, int &k)
    {
        appear_on_tour[u].push_back(k);
        tour[k++] = u;
        for (int v : t[u])
        {
            build_euler_tour_sub(v, k);
            appear_on_tour[u].push_back(k);
            tour[k++] = u;
        }
    }

    void build_euler_tour()
    {
        assert(is_built);
        tour.resize(n * 2 - 1);
        appear_on_tour.resize(n);
        int k = 0;
        build_euler_tour_sub(r, k);
    }

    void build_lca()
    {
        assert(is_built);
        for (l = 1; l <= n; l++)
        {
            if ((1 << (l - 1)) >= n)
            {
                break;
            }
        }
        anc.resize(l);
        for (int j = 0; j < l; j++)
        {
            anc[j].resize(n);
        }
        for (int i = 0; i < n; i++)
        {
            anc[0][i] = par[i];
        }
        for (int j = 1; j < l; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (anc[j - 1][i] == -1)
                {
                    anc[j][i] = -1;
                }
                else
                {
                    anc[j][i] = anc[j - 1][anc[j - 1][i]];
                }
            }
        }
        is_built_lca = true;
    }

    int ancestor(int u, int k)
    {
        assert(is_built_lca);
        for (int j = 0; j < l; j++)
        {
            if ((k >> j) & 1)
            {
                u = anc[j][u];
            }
            if (u == -1)
            {
                return u;
            }
        }
        return u;
    }

    int lca(int u, int v)
    {
        assert(is_built_lca);
        if (dpt[u] < dpt[v])
        {
            std::swap(u, v);
        }
        u = ancestor(u, dpt[u] - dpt[v]);
        if (u == v)
        {
            return u;
        }
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

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        Tree t(n);
        for(int i = 1; i < n; i++)
        {
            int p;
            cin >> p;
            p--;
            t.add_edge(i, p);
        }
        t.build(0);
        vector<int> p = t.toposort();
        ll l[200005], r[200005];
        for(int u = 0; u < n; u++)
        {
            cin >> l[u] >> r[u];
        }
        int ans = 0;
        ll d[200005];
        for(int u : p)
        {
            ll k = 0;
            for(int v : t.t[u])
            {
                k += d[v];
            }
            if(k < l[u])
            {
                d[u] = r[u];
                ans++;
            }
            else
            {
                d[u] = min(r[u], k);
            }
        }
        cout << ans << endl;
    }
}