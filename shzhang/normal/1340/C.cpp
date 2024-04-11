#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

#define INF 2000000000

#define encode(i, j) ((i) * (g + 1) + (j))

int n, m, g, r;
int d[10005];
int dist[10005][1005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", d + i);
    }
    sort(d + 1, d + m + 1);
    scanf("%d%d", &g, &r);
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= g; j++) {
            dist[i][j] = INF;
        }
    }
    /* island, time */
    deque<int> bfs;
    bfs.push_back(encode(1, 0));
    dist[1][0] = 0;
    while (!bfs.empty()) {
        int node = bfs.front();
        int island = node / (g + 1);
        int tim = node % (g + 1);
        bfs.pop_front();
        int consider[3];
        consider[0] = consider[1] = consider[2] = 0;
        if (island != m &&
            tim + d[island + 1] - d[island] <= g) {
            consider[0] = encode(island + 1,
                tim + d[island + 1] - d[island]);
        }
        if (island != 1 &&
            tim + d[island] - d[island - 1] <= g) {
            consider[1] = encode(island - 1,
                tim + d[island] - d[island - 1]);
        }
        if (tim == g) {
            consider[2] = encode(island, 0);
        }
        for (int i = 0; i < 3; i++) {
            int nxt = consider[i];
            if (!nxt) continue;
            int nxtisland = nxt / (g + 1);
            int nxttime = nxt % (g + 1);
            int len = (nxttime == 0 ? 1 : 0);
            if (dist[island][tim] + len < dist[nxtisland][nxttime]) {
                dist[nxtisland][nxttime] = dist[island][tim] + len;
                if (len) {
                    bfs.push_back(nxt);
                } else {
                    bfs.push_front(nxt);
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= g; i++) {
        if (dist[m][i] != INF)
            ans = min(ans, dist[m][i] * (r + g) + i);
    }
    printf("%d", ans == INF ? -1 : ans);
    return 0;
}