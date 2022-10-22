#include <algorithm>
#include <iostream>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
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

int rec(int u, Tree &t1, Tree &t2, set<int> &st)
{
    int v = *st.upper_bound(u);
    bool f = false;
    if (v == t1.n || t2.lca(u, v) != u)
    {
        st.insert(u);
        f = true;
    }
    int w = *--st.lower_bound(u);
    bool g = false;
    if (w >= 0 && t2.lca(u, w) == w)
    {
        st.erase(w);
        g = true;
    }
    int res = st.size();
    for (int v : t1.t[u])
    {
        res = max(res, rec(v, t1, t2, st));
    }
    if (f)
    {
        st.erase(u);
    }
    if (g)
    {
        st.insert(w);
    }
    return res;
}

void eul(int u, Tree &t, int *p, int &k)
{
    p[u] = k++;
    for (int v : t.t[u])
    {
        eul(v, t, p, k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[300005];
        for (int u = 1; u < n; u++)
        {
            cin >> a[u];
            a[u]--;
        }
        Tree t0(n);
        int b[300005];
        for (int u = 1; u < n; u++)
        {
            cin >> b[u];
            b[u]--;
            t0.add_edge(b[u], u);
        }
        t0.build(0);
        int p[300005];
        for (int u = 0; u < n; u++)
        {
            p[u] = -1;
        }
        stack<int> stk;
        stk.push(0);
        int k = 0;
        while (stk.size())
        {
            int u = stk.top();
            stk.pop();
            p[u] = k++;
            for (int v : t0.t[u])
            {
                stk.push(v);
            }
        }
        Tree t1(n), t2(n);
        for (int u = 1; u < n; u++)
        {
            t1.add_edge(p[a[u]], p[u]);
            t2.add_edge(p[b[u]], p[u]);
        }
        t1.build(0);
        t2.build(0);
        t2.build_lca();
        set<int> st;
        st.insert(-1);
        st.insert(n);
        cout << rec(0, t1, t2, st) - 2 << "\n";
    }
}