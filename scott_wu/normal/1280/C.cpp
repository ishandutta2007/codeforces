#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 500100;

int K, N;
vector <pair <int, int> > edge[MAXN];
int ssize[MAXN];

ll ans1, ans2;

void flood (int cloc, int last, ll ld)
{
    ssize[cloc] = 1;
    for (auto p : edge[cloc])
    {
        int neigh = p.first, d = p.second;
        if (neigh == last) continue;
        flood (neigh, cloc, d);
        ssize[cloc] += ssize[neigh];
    }

    if (ssize[cloc] % 2 == 1)
        ans1 += ld;
    ans2 += (min (ssize[cloc], N - ssize[cloc]) * ld);
}

void gogo()
{
    cin >> K;
    N = 2 * K;

    for (int i = 0; i < N - 1; i++)
    {
        int x, y, e;
        cin >> x >> y >> e;
        x--, y--;
        edge[x].push_back(make_pair (y, e));
        edge[y].push_back(make_pair (x, e));
    }

    ans1 = 0;
    ans2 = 0;

    flood (0, 0, 0);

    for (int i = 0; i < N; i++)
    {
        ssize[i] = 0;
        edge[i].clear();
    }

    cout << ans1 << " " << ans2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}