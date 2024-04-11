#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, K;
vector <int> edge[MAXN];
int ssize[MAXN];
vector <int> v;

void dfs (int cloc, int last, int dep)
{
    ssize[cloc] = 1;
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        dfs (neigh, cloc, dep + 1);
        ssize[cloc] += ssize[neigh];
    }
    v.push_back(ssize[cloc] - dep);
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    dfs (0, -1, 1);

    sort (v.begin(), v.end());
    reverse (v.begin(), v.end());

    ll ans = 0;
    for (int i = 0; i < N - K; i++)
        ans += v[i];
    cout << ans << "\n";
}