#include <bits/stdc++.h>
using namespace std;

#define N 2020

typedef pair <int, int> pii;
typedef pair <int, pii> pip;
#define x first
#define y second

int n, m, r, c, x, y, d[N][N];
char s[N][N];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

priority_queue <pip> pq;
void dijkstra() {
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) d[i][j] = 1e9;
    d[r][c] = 0;
    while (!pq.empty()) pq.pop();
    pq.push(make_pair(-d[r][c], pii(r, c)));
    while (!pq.empty()) {
        pip pp = pq.top(); pq.pop();
        int u = pp.y.x, v = pp.y.y, w = -pp.x;
        if (d[u][v] != w) continue;
        for (int i = 0; i < 4; i ++) {
            int a = u + dx[i], b = v + dy[i], ww = w;
            if (s[a][b] != '.') continue;
            if (i == 0) ww ++;
            if (ww > y || c + ww - b > x) continue;
            if (d[a][b] > ww) {
                d[a][b] = ww;
                pq.push(pip(-d[a][b], pii(a, b)));
            }
        }
    }
}


int main() {
    scanf("%d %d %d %d %d %d", &n, &m, &r, &c, &x, &y);
    for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
    dijkstra();
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) if (d[i][j] < 1e9) ans ++;
    printf("%d\n", ans);
}