#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = 500100;

int Q;

int N, K;
vector <pair <int, int> > edge[MAXN];
ll dpg[MAXN], dpn[MAXN];

void flood (int cloc, int last)
{
    vector <ll> inc;
    ll tot = 0;
    ll pscore = 0;
    for (auto p : edge[cloc])
    {
        int neigh = p.first;
        if (neigh == last)
        {
            pscore = p.second;
            continue;
        }

        flood (neigh, cloc);
        tot += dpn[neigh];
        inc.push_back (max (dpg[neigh] - dpn[neigh], (ll) 0));
    }
    sort (inc.begin(), inc.end());
    reverse (inc.begin(), inc.end());

    for (int i = 0; i < inc.size() && i < K - 1; i++)
        tot += inc[i];

    dpn[cloc] = tot;
    dpg[cloc] = tot + pscore;
    if (inc.size() >= K)
        dpn[cloc] += inc[K-1];

    //cout << cloc << " " << dpn[cloc] << " " << dpg[cloc] << "\n";
}

void roll()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        edge[i].clear();
        dpn[i] = dpg[i] = 0;
    }

    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[u].push_back(make_pair(v, w));
        edge[v].push_back(make_pair(u, w));
    }

    flood (0, -1);
    cout << max (dpn[0], dpg[0]) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> Q;
    for (int q = 0; q < Q; q++)
        roll();
}