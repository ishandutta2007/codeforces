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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int d[1005];
        for (int u = 0; u < n; u++)
        {
            cin >> d[u];
        }
        bool b[1005]{0};
        UnionFind uf(n);
        while (true)
        {
            int r = -1;
            for (int u = 0; u < n; u++)
            {
                if (!b[u] && (r == -1 || d[u] > d[r]))
                {
                    r = u;
                }
            }
            if (r == -1)
            {
                break;
            }
            b[r] = true;
            for (int i = 0; i < d[r]; i++)
            {
                cout << "? " << r + 1 << endl;
                int u;
                cin >> u;
                u--;
                uf.unite(r, u);
                if (b[u])
                {
                    break;
                }
                b[u] = true;
            }
        }
        cout << "! ";
        for (int u = 0; u < n; u++)
        {
            cout << uf.find(u) + 1 << " ";
        }
        cout << endl;
    }
}