#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 500100;

int N;
vector <int> edge[MAXN];
int par[MAXN];
int dep[MAXN];
int pdep[MAXN];
vector <int> ndeps[MAXN];
vector <int> nadd[MAXN];

int oans[MAXN];
int eans[MAXN];

void flood (int cloc, int last)
{
    par[cloc] = last;
    dep[cloc] = 0;
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        flood (neigh, cloc);
        dep[cloc] = max (dep[cloc], dep[neigh] + 1);
        ndeps[cloc].push_back(dep[neigh] + 1);
    }
}

void pflood (int cloc, int pd)
{
    if (cloc) ndeps[cloc].push_back(0);
    pdep[cloc] = pd;
    ndeps[cloc].push_back(pd);
    sort(ndeps[cloc].begin(), ndeps[cloc].end());
    int nn = ndeps[cloc].size();
    for (int i = 0; i < ndeps[cloc].size(); i++)
        nadd[cloc].push_back(0);

    for (int neigh : edge[cloc])
    {
        if (neigh == par[cloc]) continue;
        if (dep[neigh] + 1 == ndeps[cloc][nn-1])
        {
            int pneigh = 0;
            if (nn >= 2) pneigh = ndeps[cloc][nn-2];
            pflood (neigh, max (pd, pneigh) + 1);
        }
        else
            pflood (neigh, max (pd, ndeps[cloc][nn-1]) + 1);
    }
}

void lessgo (int x, int y)
{
    if (ndeps[x].size() < ndeps[y].size())
        swap (x, y);

    for (int i = 0; i < ndeps[y].size(); i++)
    {
        int cd = ndeps[y][i];

        int nk = lower_bound(ndeps[x].begin(), ndeps[x].end(), cd) - ndeps[x].begin();
        int nplus = ndeps[x].size() - nk;
        oans[cd] = max (oans[cd], nplus + ((int) ndeps[y].size() - i) - 2);

        int np = upper_bound(ndeps[x].begin(), ndeps[x].end(), cd) - ndeps[x].begin();
        np--;
        if (np >= 0)
            nadd[x][np] = max (nadd[x][np], ((int) ndeps[y].size() - i) - 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i + 1 < N; i++)
    {
        int x, y; cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    flood (0, 0);
    pflood (0, 0);

    for (int i = 0; i < MAXN; i++)
        oans[i] = eans[i] = 0;

    for (int i = 1; i < N; i++)
    {
        lessgo (i, par[i]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = ndeps[i].size() - 1; j >= 0; j--)
        {
            oans[ndeps[i][j]] = max (oans[ndeps[i][j]], nadd[i][j] + ((int) ndeps[i].size() - j));
            if (j) nadd[i][j-1] = max (nadd[i][j-1], nadd[i][j]);
        }
    }
    for (int i = N+5; i > 0; i--)
        oans[i-1] = max (oans[i-1], oans[i]);

    for (int i = 0; i < N; i++)
    {
        for (int j = ndeps[i].size() - 1; j >= 0; j--)
        {
            eans[ndeps[i][j]] = max (eans[ndeps[i][j]], (int) ndeps[i].size() - j);
            if (j == ndeps[i].size() - 1 || ndeps[i][j] < ndeps[i][j+1])
                eans[ndeps[i][j]+1] = max (eans[ndeps[i][j]+1], (int) ndeps[i].size() - j);
        }
        eans[1] = max (eans[1], (int) ndeps[i].size());
    }
    for (int i = N+5; i > 0; i--)
        eans[i-1] = max (eans[i-1], eans[i]);

    for (int x = 1; x <= N; x++)
    {
        int ans;
        if (x % 2 == 1)
            ans = eans[(x+1)/2];
        else
            ans = oans[x/2];

        ans = max (ans, 1);
        if (x > 1) cout << " ";
        cout << ans;
    }
    cout << "\n";
}