#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 3e3 + 10;
const int INF = 1e9;

vector<int> adj[MAXN];
int dist[MAXN][MAXN], n, m;

void BFS(int s) {
        dist[s][s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                        if (dist[s][u] == INF) {
                                dist[s][u] = dist[s][v] + 1;
                                q.push(u);
                        }
                }
        }
}

int main() {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dist[i][j] = INF;
        for (int i = 1; i <= n; i++) BFS(i);

        int s1, t1, l1, s2, t2, l2;
        scanf("%d %d %d", &s1, &t1, &l1);
        scanf("%d %d %d", &s2, &t2, &l2);
        if (dist[s1][t1] > l1 || dist[s2][t2] > l2) return cout << -1 << endl, 0;
        int ans = m - dist[s1][t1] - dist[s2][t2];
        for (int v1 = 1; v1 <= n; v1++) {
                for (int v2 = 1; v2 <= n; v2++) {
                        int d = dist[v1][v2];
                        int d_1 = dist[s1][v1] + d + dist[v2][t1];
                        int d_2 = dist[s2][v1] + d + dist[v2][t2];
                        if (d_1 <= l1 && d_2 <= l2) ans = max(ans, m - d_1 - d_2 + d);
                        d_2 = dist[s2][v2] + d + dist[v1][t2];
                        if (d_1 <= l1 && d_2 <= l2) ans = max(ans, m - d_1 - d_2 + d);
                }
        }

        cout << ans << endl;
        return 0;
}