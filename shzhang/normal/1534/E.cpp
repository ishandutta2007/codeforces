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

vector<int> graph[505];
int n, k;
bool vis[505]; int dist[505];
bool inuse[505];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; i++) {
        for (int x = 0; x <= min(i, k); x++) {
            if (n - i < k - x) continue;
            graph[i].push_back(i - 2 * x + k);
            //printf("%d %d\n", i, i - 2 * x + k);
        }
    }
    queue<int> bfs;
    bfs.push(n); dist[n] = 0; vis[n] = true;
    while (!bfs.empty()) {
        int node = bfs.front(); bfs.pop();
        for (int i = 0; i < graph[node].size(); i++) {
            int nxt = graph[node][i];
            if (vis[nxt]) continue;
            vis[nxt] = true; dist[nxt] = dist[node] + 1;
            bfs.push(nxt);
        }
    }
    if (!vis[0]) {
        printf("-1"); fflush(stdout); return 0;
    }
    int cur = 0;
    int ans = 0;
    while (cur < n) {
        int nxt = -1;
        for (int i = 0; i < graph[cur].size(); i++) {
            int x = graph[cur][i];
            if (dist[x] == dist[cur] - 1) {
                nxt = x; break;
            }
        }
        int takecnt = (cur + k - nxt) / 2;
        int addcnt = k - takecnt;
        vector<int> changes;
        for (int i = 1; i <= n; i++) {
            if (inuse[i] && takecnt) {
                changes.push_back(i); takecnt--;
            } else if (!inuse[i] && addcnt) {
                changes.push_back(i); addcnt--;
            }
        }
        printf("? ");
        for (int i = 0; i < changes.size(); i++) {
            printf("%d ", changes[i]);
        }
        printf("\n"); fflush(stdout);
        int result; scanf("%d", &result);
        ans ^= result;
        for (int i = 0; i < changes.size(); i++) {
            inuse[changes[i]] = !inuse[changes[i]];
        }
        cur = nxt;
    }
    printf("! %d\n", ans); fflush(stdout);
    return 0;
}