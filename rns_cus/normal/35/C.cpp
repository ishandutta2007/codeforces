#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
#define N 2020
int n, m, k;
bool vis[N][N];

typedef pair <int, int> pii;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    queue <pii> Q;
    while (k --) {
        int x, y;
        scanf("%d %d", &x, &y);
        vis[x][y] = 1;
        Q.emplace(x, y);
    }
    pii p;
    while (!Q.empty()) {
        p = Q.front(); Q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; i ++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (1 <= xx && xx <= n && 1 <= yy && yy <= m && !vis[xx][yy]) vis[xx][yy] = 1, Q.emplace(xx, yy);
        }
    }
    printf("%d %d\n", p.first, p.second);

    return 0;
}