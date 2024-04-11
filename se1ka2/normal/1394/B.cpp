#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int M = 200005;

vector<P> g[200005];
vector<int> x[12];
bool b[12][12][12][12];
bool o[12][12];

int rec(int c, int k, int *d)
{
    if (c == k + 1)
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < c; i++)
    {
        bool f = o[c][i];
        for (int e = 1; e < c; e++)
        {
            if (!b[c][i][e][d[e]])
            {
                f = false;
            }
        }
        if (f)
        {
            d[c] = i;
            res += rec(c + 1, k, d);
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back(P(w, v));
    }
    for (int u = 0; u < n; u++)
    {
        x[g[u].size()].push_back(u);
    }
    int d[200005]{0};
    for(int c = 1; c <= k; c++)
    {
        for(int i = 0; i < c; i++)
        {
            o[c][i] = true;
            for(int u : x[c])
            {
                int v = g[u][i].second;
                if(d[v])
                {
                    o[c][i] = false;
                }
                d[v]++;
            }
            for(int u : x[c])
            {
                int v = g[u][i].second;
                d[v]--;
            }
        }
    }
    for (int c = 1; c <= k; c++)
    {
        for (int i = 0; i < c; i++)
        {
            for (int e = 1; e <= c; e++)
            {
                for (int j = 0; j < e; j++)
                {
                    b[c][i][e][j] = true;
                    for (int u : x[c])
                    {
                        int v = g[u][i].second;
                        if (d[v])
                        {
                            b[c][i][e][j] = false;
                        }
                        d[v]++;
                    }
                    for (int u : x[e])
                    {
                        int v = g[u][j].second;
                        if (d[v])
                        {
                            b[c][i][e][j] = false;
                        }
                        d[v]++;
                    }
                    for (int u : x[c])
                    {
                        int v = g[u][i].second;
                        d[v]--;
                    }
                    for (int u : x[e])
                    {
                        int v = g[u][j].second;
                        d[v]--;
                    }
                }
            }
        }
    }
    int p[12];
    cout << rec(1, k, p) << "\n";
}