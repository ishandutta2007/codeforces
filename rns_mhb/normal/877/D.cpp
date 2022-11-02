#include <bits/stdc++.h>
using namespace std;

#define N 1010

int dist[N][N];
char s[N][N];
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
queue <pair <int, int> > Q;

const int inf = 1e9;

int n, m, k;
int x, y, xx, yy, xxx, yyy;

int main() {
   /// freopen("r.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s[i] + 1);
    }

    scanf("%d %d %d %d", &x, &y, &xx, &yy);

   /// cout << xx << " " << yy << endl;
   ///cout << k << endl;

    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) dist[i][j] = inf;
    }

    dist[x][y] = 0;
    Q.push(make_pair(x, y));
    while (!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();

        for (int t = 0; t < 4; t ++) {
            xxx = x, yyy = y;
            for (int i = 1; i <= k; i ++) {
                xxx += dx[t];
                yyy += dy[t];
                if (xxx < 1 || yyy < 1 || xxx > n || yyy > m) break;
                if (s[xxx][yyy] == '#') break;
                if (dist[xxx][yyy] <= dist[x][y]) break;
                else if (dist[xxx][yyy] == inf) {
                    dist[xxx][yyy] = dist[x][y] + 1;
                    Q.push(make_pair(xxx, yyy));
                }
            }
        }
    }

    if (dist[xx][yy] == inf) { puts("-1"); return 0; }
    printf("%d\n", dist[xx][yy]);
}