#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define INF 1000000000000000000LL
ll dist[605][605];
ll wt[605][605];
bool hasedge[605][605];
vector<pair<int, ll> > queries[605];
ll maxval[605];
bool useful[605][605];

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) dist[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v; ll l; scanf("%d%d%lld", &u, &v, &l);
        dist[u][v] = l;
        dist[v][u] = l;
        hasedge[u][v] = hasedge[v][u] = true;
        wt[u][v] = wt[v][u] = l;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int u, v; ll l; scanf("%d%d%lld", &u, &v, &l);
        queries[u].push_back(make_pair(v, l));
    }
    for (int u = 1; u <= n; u++) {
        for (int i = 1; i <= n; i++) maxval[i] = -INF;
        for (int idx = 0; idx < queries[u].size(); idx++) {
            int v = queries[u][idx].first;
            ll l = queries[u][idx].second;
            for (int y = 1; y <= n; y++) {
                maxval[y] = max(maxval[y], l - dist[y][v]);
            }
        }
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (!hasedge[x][y]) continue;
                if (useful[x][y]) continue;
                if (dist[u][x] + wt[x][y] <= maxval[y]) useful[x][y] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!hasedge[i][j]) continue;
            if (useful[i][j] || useful[j][i]) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}