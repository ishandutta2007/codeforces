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

int a[1000005];
vector<pair<int, int> > graph[500005]; bool vis[500005];
bool use[1000005];

int main()
{
    int n; scanf("%d", &n);
    if (n % 2 == 0) {
        printf("First\n");
        for (int i = 1; i <= n; i++) printf("%d ", i);
        for (int i = 1; i <= n; i++) printf("%d ", i);
        printf("\n"); fflush(stdout);
        int result; scanf("%d", &result);
    } else {
        printf("Second\n"); fflush(stdout);
        for (int i = 1; i <= 2 * n; i++) {
            scanf("%d", a + i);
        }
        for (int i = 1; i <= n; i++) {
            int x = a[i]; int y = a[n + i];
            graph[x].push_back(make_pair(y, i));
            graph[y].push_back(make_pair(x, n + i));
            //printf("%d %d\n", x, y);
        }
        ll tot = 0;
        for (int i = 1; i <= n; i++) {
            int cur = i;
            if (vis[i]) continue;
            int prev_edge = -1;
            while (true) {
                int nxt = 0;
                for (int j = 0; j < graph[cur].size(); j++) {
                    if (graph[cur][j].second % n == prev_edge) continue;
                    nxt = graph[cur][j].first;
                    if (vis[nxt]) goto after;
                    //printf("%d\n", graph[cur][j].second);
                    use[graph[cur][j].second] = true;
                    prev_edge = graph[cur][j].second % n;
                    tot += (ll)graph[cur][j].second;
                    break;
                }
                if (!nxt) break;
                //printf("%d -> %d\n", cur, nxt);
                cur = nxt;
                vis[cur] = true;
            }
            after:
            ;
        }
        if (tot % (ll)(2 * n)) {
            for (int i = 1; i <= 2 * n; i++) {
                if (!use[i]) printf("%d ", i);
            }
        } else {
            for (int i = 1; i <= 2 * n; i++) {
                if (use[i]) printf("%d ", i);
            }
        }
        fflush(stdout);
        int res; scanf("%d", &res);
    }
    return 0;
}