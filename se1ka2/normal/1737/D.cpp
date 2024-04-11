#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
typedef long long ll;

const int INF = 1000000000;
const ll INFll = 1000000000000000000;

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
};

int d[505][505];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int a[250005], b[250005];
        ll w[250005];
        for(int u = 0; u < n; u++)
        {
            for(int v = 0; v < n; v++)
            {
                d[u][v] = INF;
            }
            d[u][u] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> a[i] >> b[i] >> w[i];
            a[i]--;
            b[i]--;
            d[a[i]][b[i]] = d[b[i]][a[i]] = 1;
        }
        for(int w = 0; w < n; w++)
        {
            for(int u = 0; u < n; u++)
            {
                for(int v = 0; v < n; v++)
                {
                    d[u][v] = min(d[u][v], d[u][w] + d[w][v]);
                }
            }
        }
        ll ans = INFll;
        for(int i = 0; i < m; i++)
        {
            ans = min(ans, (min(d[0][a[i]] + d[b[i]][n - 1], d[0][b[i]] + d[a[i]][n - 1]) + 1) * w[i]);
            for(int u = 0; u < n; u++)
            {
                ans = min(ans, (min(d[a[i]][u], d[b[i]][u]) + d[0][u] + d[u][n - 1] + 2) * w[i]);
            }
        }
        cout << ans << "\n";
    }
}