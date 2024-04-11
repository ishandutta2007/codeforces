#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    std::vector<int> par;
    std::vector<int> sz;
    int c;

    UnionFind(int n)
    {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
        c = n;
    }

    int find(int i)
    {
        if (i == par[i])
        {
            return i;
        }
        return par[i] = find(par[i]);
    }

    bool same(int i, int j)
    {
        return find(i) == find(j);
    }

    void unite(int i, int j)
    {
        i = find(i), j = find(j);
        if (i == j)
        {
            return;
        }
        if (sz[i] < sz[j])
        {
            std::swap(i, j);
        }
        par[j] = i;
        sz[i] += sz[j];
        c--;
    }

    int size(int i)
    {
        return sz[find(i)];
    }

    int count()
    {
        return c;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int u[200005], v[200005];
        UnionFind uf(n);
        bool b[200005];
        bool ans[200005];
        for (int u = 0; u < n; u++)
        {
            b[u] = false;
        }
        for (int i = 0; i < m; i++)
        {
            ans[i] = false;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> u[i] >> v[i];
            u[i]--;
            v[i]--;
            if (!uf.same(u[i], v[i]))
            {
                uf.unite(u[i], v[i]);
            }
            else if (!b[u[i]] || !b[v[i]])
            {
                b[u[i]] = b[v[i]] = true;
                ans[i] = true;
            }
            else
            {
                UnionFind uf2(n);
                for(int j = 0; j < m; j++)
                {
                    uf2.unite(u[j], v[j]);
                    if(uf2.same(u[i], v[i]))
                    {
                        ans[j] = true;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            cout << ans[i];
        }
        cout << "\n";
    }
}