#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N, M, K;
vector <pair <pair <int, int>, int> > edge[MAXN];

priority_queue <pair <pair <ll, int>, int> > q;

ll dist[MAXN];
vector <int> res;

void gogo()
{
    for (int i = 0; i < N; i++)
        dist[i] = 1e15;
    dist[0] = 0;
    q.push(make_pair(make_pair(0, 0), -1));

    while (!q.empty())
    {
        auto c = q.top();
        ll cd = -c.first.first;
        int cloc = c.first.second;
        int clast = c.second;
        q.pop();

        if (cd != dist[cloc])
            continue;
        if (clast != -1)
            res.push_back(clast);

        for (auto ninfo : edge[cloc])
        {
            int neigh = ninfo.first.first, ndist = ninfo.first.second, nind = ninfo.second;
            if (ndist + cd < dist[neigh])
            {
                dist[neigh] = ndist + cd;
                q.push(make_pair(make_pair(-dist[neigh], neigh), nind));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        edge[x].push_back(make_pair(make_pair(y, w), i + 1));
        edge[y].push_back(make_pair(make_pair(x, w), i + 1));
    }

    gogo();
    int ans = min (K, (int) res.size());
    cout << ans << "\n";
    for (int i = 0; i < ans; i++)
        cout << res[i] << " ";
    cout << "\n";
}