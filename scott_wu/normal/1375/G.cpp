#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
vector <int> edge[MAXN];
int par[MAXN];
int dep[MAXN];

void flood (int cloc, int cdep, int last)
{
    par[cloc] = last;
    dep[cloc] = cdep;
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        flood (neigh, cdep + 1, cloc);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    flood (0, 0, -1);

    int n0 = 0;
    for (int i = 0; i < N; i++)
        if (dep[i] % 2 == 0)
            n0++;
    n0 = min (n0, N - n0);
    cout << n0 - 1 << "\n";
}