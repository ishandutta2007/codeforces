#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
vector <int> edge[MAXN];
vector <int> par;
int ans;

void flood (int cloc, int clast, int cdep)
{
    if (edge[cloc].size() == 1)
    {
        par.push_back(cdep);
    }

    int nleaf = 0;
    for (int neigh : edge[cloc])
    {
        if (neigh == clast) continue;
        if (edge[neigh].size() == 1)
            nleaf++;
        flood (neigh, cloc, cdep + 1);
    }

    if (nleaf)
        ans -= (nleaf - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int root = 0;
    while (edge[root].size() == 1)
        root++;

    ans = N - 1;
    flood (root, -1, 0);

    bool bg = true;
    for (int i = 0; i + 1 < par.size(); i++)
        if (par[i] % 2 != par[i+1] % 2)
            bg = false;
    if (bg)
        cout << "1 ";
    else
        cout << "3 ";
    cout << ans << "\n";
}