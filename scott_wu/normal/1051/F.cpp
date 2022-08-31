#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, M;
vector <pair <int, int> > edge[MAXN];
int par[MAXN][20];
vector <int> vspec;
int dep[MAXN];
ll ddep[MAXN];
int Q;
pair <int, int> query[MAXN];
ll ans[MAXN];

void dfs (int cloc, int last)
{
    par[cloc][0] = last;
    for (int i = 1; i < 20; i++) par[cloc][i] = par[par[cloc][i-1]][i-1];

    for (pair <int, int> pp : edge[cloc])
    {
        int neigh = pp.first, d = pp.second;
        if (neigh == last) continue;
        if (par[neigh][0] != -1)
        {
            if (dep[cloc] > dep[neigh]) vspec.push_back(neigh);
            continue;
        }
        dep[neigh] = dep[cloc] + 1;
        ddep[neigh] = ddep[cloc] + d;
        dfs (neigh, cloc);
    }
}

int lca (int x, int y)
{
    if (dep[x] < dep[y]) swap (x, y);
    for (int i = 0; i < 20; i++)
        if ((dep[x] - dep[y]) & (1 << i))
            x = par[x][i];
    if (x == y) return x;
    for (int i = 19; i >= 0; i--)
        if (par[x][i] != par[y][i])
        {
            x = par[x][i];
            y = par[y][i];
        }
    return par[x][0];
}

ll gdist (int x, int y)
{
    int l = lca (x, y);
    return ddep[x] + ddep[y] - 2 * ddep[l];
}

ll cd[MAXN];

void flood (int cloc, ll cdist)
{
    cd[cloc] = cdist;
    for (pair <int, int> pp : edge[cloc])
    {
        int neigh = pp.first, d = pp.second;
        if (cd[neigh] > cdist + d)
            flood (neigh, cdist + d);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        edge[a].emplace_back(b, d);
        edge[b].emplace_back(a, d);
    }
    for (int i = 0; i < N; i++)
        par[i][0] = -1;

    dfs (0, 0);
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> query[i].first >> query[i].second;
        query[i].first--;
        query[i].second--;

        ans[i] = gdist (query[i].first, query[i].second);
    }

    for (int i = 0; i < vspec.size(); i++)
    {
        for (int j = 0; j < N; j++)
            cd[j] = 1e15;
        flood (vspec[i], 0);
        for (int j = 0; j < Q; j++)
        {
            ans[j] = min (ans[j], cd[query[j].first] + cd[query[j].second]);
        }
    }
    for (int i = 0; i < Q; i++)
        cout << ans[i] << "\n";
}