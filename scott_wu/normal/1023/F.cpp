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
const int MAXN = 500100;
const int MAXT = 20;

int N, K, M;
vector <pair <int, int> > edge[MAXN];
int ne;
int eleft[MAXN], eright[MAXN], ecost[MAXN];

int ptype[MAXN];
int par[MAXN][MAXT];
int ccost[MAXN][MAXT];
int cdep[MAXN];

int upar[MAXN];
int ufind (int x)
{
    if (x == upar[x]) return x;
    return upar[x] = ufind (upar[x]);
}

void uni (int left, int right)
{
    left = ufind (left), right = ufind (right);
    upar[left] = right;
}

void flood (int cloc, int last)
{
    par[cloc][0] = last;
    for (pair <int, int> pp : edge[cloc])
    {
        int neigh = pp.first, ntype = pp.second;
        if (neigh == last) continue;
        ptype[neigh] = ntype;
        cdep[neigh] = cdep[cloc] + 1;
        flood (neigh, cloc);
    }
}

void apply (int left, int right, int cost)
{
    if (cdep[left] < cdep[right])
        swap (left, right);

    int nd = cdep[left] - cdep[right];
    for (int i = 0; i < MAXT; i++)
    {
        if (nd & (1 << i))
        {
            ccost[left][i] = min (ccost[left][i], cost);
            left = par[left][i];
        }
    }

    if (left == right) return;
    for (int i = MAXT - 1; i >= 0; i--)
    {
        if (par[left][i] != par[right][i])
        {
            ccost[left][i] = min (ccost[left][i], cost);
            ccost[right][i] = min (ccost[right][i], cost);
            left = par[left][i];
            right = par[right][i];
        }
    }
    ccost[left][0] = min (ccost[left][0], cost);
    ccost[right][0] = min (ccost[right][0], cost);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 0; i < MAXN; i++)
        upar[i] = i;
    cin >> N >> K >> M;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        uni (x, y);
        edge[x].push_back(make_pair(y, 1));
        edge[y].push_back(make_pair(x, 1));
    }
    for (int i = 0; i < M; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        if (ufind (x) != ufind (y))
        {
            uni (x, y);
            edge[x].push_back(make_pair(y, 0));
            edge[y].push_back(make_pair(x, 0));
        }
        else
        {
            eleft[ne] = x;
            eright[ne] = y;
            ecost[ne] = c;
            ne++;
        }
    }

    flood (0, -1);

    par[0][0] = 0;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXT; j++)
            ccost[i][j] = 2e9;
    for (int i = 1; i < MAXT; i++)
    {
        for (int j = 0; j < N; j++)
        {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }

    for (int i = 0; i < ne; i++)
        apply (eleft[i], eright[i], ecost[i]);
    for (int i = MAXT - 1; i >= 1; i--)
    {
        for (int j = 0; j < N; j++)
        {
            int nj = par[j][i-1];
            ccost[j][i-1] = min (ccost[j][i-1], ccost[j][i]);
            ccost[nj][i-1] = min (ccost[nj][i-1], ccost[j][i]);
        }
    }

    ll res = 0;
    for (int i = 1; i < N; i++)
    {
        if (ptype[i])
        {
            if (ccost[i][0] > 1.1e9)
            {
                res = -1;
                break;
            }
            res += ccost[i][0];
        }
    }
    cout << res << "\n";
}