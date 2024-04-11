#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N;
vector <pair <int, int> > edge[MAXN];
int par[MAXN];
int pval[MAXN];
int deg[MAXN];
int dep[MAXN];
vector <pair <pair <int, int>, int> > res;
int baby[MAXN];

void flood (int cloc, int last)
{
    par[cloc] = last;
    for (auto p : edge[cloc])
    {
        int neigh = p.first;
        if (neigh == last)
        {
            pval[cloc] = p.second;
        }
        else
        {
            dep[neigh] = dep[cloc] + 1;
            flood (neigh, cloc);
        }
    }
}

void roll (int x, int y, int amt)
{
    res.push_back(make_pair(make_pair (x, y), amt));
    if (dep[x] < dep[y]) swap (x, y);
    while (dep[x] > dep[y])
    {
        pval[x] -= amt;
        x = par[x];
    }
    while (x != y)
    {
        pval[x] -= amt;
        x = par[x];
        pval[y] -= amt;
        y = par[y];
    }
}

void flood2 (int cloc)
{
    if (edge[cloc].size() == 1)
        return;
    vector <pair <int, int> > vv;
    for (auto p : edge[cloc])
    {
        int neigh = p.first;
        if (par[neigh] == cloc)
        {
            vv.push_back(make_pair(neigh, baby[neigh]));
        }
        else
        {
            for (auto q : edge[neigh])
            {
                int nn = q.first;
                if (nn != cloc && nn != par[neigh])
                {
                    vv.push_back(make_pair(neigh, baby[nn]));
                    break;
                }
            }
        }
    }

    int m = vv.size();
    for (int i = 0; i < m; i++)
    {
        int neigh = vv[i].first;
        if (par[neigh] != cloc) continue;
        int b1 = vv[(i+1)%m].second;
        int b2 = vv[(i+2)%m].second;
        int b = vv[i].second;
        int amt = pval[neigh] / 2;
        roll(b, b1, amt);
        roll(b, b2, amt);
        roll(b1, b2, -amt);
    }

    for (auto p : edge[cloc])
    {
        int neigh = p.first;
        if (par[neigh] == cloc)
            flood2(neigh);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        deg[i] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        x--, y--;
        deg[x]++;
        deg[y]++;
        edge[x].push_back(make_pair (y, v));
        edge[y].push_back(make_pair (x, v));
    }

    bool found = false;
    for (int i = 0; i < N; i++)
        if (deg[i] == 2)
            found = true;

    if (found)
    {
        cout << "NO\n";
        return 0;
    }
    else
        cout << "YES\n";

    if (N == 2)
    {
        cout << "1\n1 2 " << edge[0][0].second << "\n";
        return 0;
    }
    int cloc = 0;
    while (deg[cloc] == 1)
        cloc++;

    dep[cloc] = 0;
    flood (cloc, -1);
    for (int i = 0; i < N; i++)
    {
        if (deg[i] == 1)
        {
            int floc = i;
            while (floc >= 0)
            {
                baby[floc] = i;
                floc = par[floc];
            }
        }
    }

    flood2 (cloc);

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        int a = res[i].first.first, b = res[i].first.second, c = res[i].second;
        cout << a + 1 << " " << b + 1 << " " << c << "\n";
    }
}