#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

#define ll long long
#define add(x, y) {if (!vis[x][y]) {bfs.push(make_pair(x, y)); \
    vis[x][y] = true; tim[x][y] = tim[pos.first][pos.second] + 1;}}

bool clr[1005][1005];
char s[1005];
int tim[1005][1005];
bool vis[1005][1005];

int n, m, t;

int main()
{
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            tim[i][j] = -1;
            if (s[j] == '1') clr[i][j] = true;
        }
    }
    queue<pair<int, int> > bfs;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i > 1 && clr[i][j] == clr[i-1][j]) ||
                (i < n && clr[i][j] == clr[i+1][j]) ||
                (j > 1 && clr[i][j] == clr[i][j-1]) ||
                (j < m && clr[i][j] == clr[i][j+1])) {
                tim[i][j] = 0;
                bfs.push(make_pair(i, j));
                vis[i][j] = true;
            }
        }
    }
    while (!bfs.empty()) {
        pair<int, int> pos = bfs.front();
        bfs.pop();
        if (pos.first > 1) add(pos.first - 1, pos.second);
        if (pos.first < n) add(pos.first + 1, pos.second);
        if (pos.second > 1) add(pos.first, pos.second - 1);
        if (pos.second < m) add(pos.first, pos.second + 1);
    }
    for (int q = 1; q <= t; q++) {
        int i, j; ll p;
        scanf("%d%d%lld", &i, &j, &p);
        if (tim[i][j] == -1 || p <= tim[i][j]) {
            printf("%d\n", (int)clr[i][j]);
        } else {
            ll dif = p - (ll)tim[i][j];
            if (dif % 2 == 0) {
                printf("%d\n", (int)clr[i][j]);
            } else {
                printf("%d\n", (int)(!clr[i][j]));
            }
        }
    }
    return 0;
}