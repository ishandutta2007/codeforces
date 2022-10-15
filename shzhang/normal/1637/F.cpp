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
#include <map>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n;

ll h[200005];
vector<int> graph[200005];
map<int, int> wt[200005];
map<int, ll> f[200005];
ll hmax[200005];
int weight[200005];
vector<pair<int, pair<int, int> > > pairs;
int parent[200005];
int parentcnt[200005];
ll fsum[200005];

void dfs(int node, int prt)
{
    weight[node] = 1;
    parent[node] = prt;
    hmax[node] = h[node];
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs(nxt, node);
        weight[node] += weight[nxt];
        hmax[node] = max(hmax[node], hmax[nxt]);
    }
    if (prt) {
        wt[node][prt] = weight[node];
        pairs.push_back(make_pair(weight[node], make_pair(node, prt)));
    }
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        wt[node][nxt] = n - weight[nxt];
        pairs.push_back(make_pair(n - weight[nxt], make_pair(node, nxt)));
    }
}

int main()
{
    scanf("%d", &n);
    int maxht = 0, maxnode = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", h + i);
        if (h[i] > maxht) {
            maxnode = i; maxht = h[i];
        }
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(maxnode, 0);
    sort(pairs.begin(), pairs.end());
    vector<ll> adjmaxs;
    for (int i = 0; i < graph[maxnode].size(); i++) {
        adjmaxs.push_back(hmax[graph[maxnode][i]]);
    }
    adjmaxs.push_back(0);
    sort(adjmaxs.begin(), adjmaxs.end());
    reverse(adjmaxs.begin(), adjmaxs.end());
    for (int idx = 0; idx < pairs.size(); idx++) {
        pair<int, int> pr = pairs[idx].second;
        ll addval = 0;
        if (pr.first == maxnode) {
            ll maxv;
            if (hmax[pr.second] == adjmaxs[0]) {
                maxv = adjmaxs[1];
            } else {
                maxv = adjmaxs[0];
            }
            addval = max(h[pr.first] - maxv, 0LL);
        } else if (pr.second == parent[pr.first]) {
            ll maxv = 0;
            for (int j = 0; j < graph[pr.first].size(); j++) {
                int nxt = graph[pr.first][j];
                if (nxt == pr.second) continue;
                maxv = max(maxv, hmax[nxt]);
            }
            addval = max(h[pr.first] - maxv, 0LL);
        }
        ll totdown = fsum[pr.first];
        if (parentcnt[pr.first] == graph[pr.first].size()) {
            totdown -= f[pr.second][pr.first];
        }
        f[pr.first][pr.second] = totdown + addval;
        //printf("%d %d %lld\n", pr.first, pr.second, f[pr.first][pr.second]);
        parentcnt[pr.second]++;
        fsum[pr.second] += f[pr.first][pr.second];
    }
    ll ans = 1000000000000000000LL;
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() == 1) {
            ll newans = f[graph[i][0]][i];
            if (i == maxnode) newans += maxht - hmax[graph[i][0]];
            ans = min(ans, newans);
        }
    }
    printf("%lld", ans + maxht);
    return 0;
}