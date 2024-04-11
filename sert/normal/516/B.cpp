#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 2034;

ll n, m, x, y, xx, yy, kol;
char s[N][N];
bool u[N][N];
queue <pair<ll, ll> > q;

int cnt(int y, int x) {
    return (s[y-1][x]=='.')+(s[y+1][x]=='.')+(s[y][x-1]=='.')+(s[y][x+1]=='.');
}

void fail() {
    printf("Not unique\n");
    exit(0);
}

int main() {

    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d%d ", &n, &m);

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            s[i][j] = '*';

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%c ", &s[i+1][j+1]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i][j] == '.') {
                kol--;
                if (cnt(i, j) == 1)
                    q.push(make_pair(i, j));
            }

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        if (u[y][x]) continue;
        u[y][x] = true;
        kol += 2;
        if (cnt(y, x) == 0) fail();
        if (s[y-1][x] == '.') {
            u[y-1][x] = true;
            s[y][x] = 'v';
            s[y-1][x] = '^';
            xx = x;
            yy = y - 1;
        } else
        if (s[y+1][x] == '.') {
            u[y+1][x] = true;
            s[y][x] = '^';
            s[y+1][x] = 'v';
            xx = x;
            yy = y + 1;
        } else
        if (s[y][x+1] == '.') {
            u[y][x+1] = true;
            s[y][x] = '<';
            s[y][x+1] = '>';
            xx = x + 1;
            yy = y;
        } else
        if (s[y][x-1] == '.') {
            u[y][x-1] = true;
            s[y][x] = '>';
            s[y][x-1] = '<';
            xx = x - 1;
            yy = y;
        } else fail();
        if (s[yy][xx - 1] == '.')
            if (cnt(yy, xx - 1) == 1)
                q.push(make_pair(yy, xx - 1));
        if (s[yy][xx + 1] == '.')
            if (cnt(yy, xx + 1) == 1)
                q.push(make_pair(yy, xx + 1));
        if (s[yy - 1][xx] == '.')
            if (cnt(yy - 1, xx) == 1)
                q.push(make_pair(yy - 1, xx));
        if (s[yy + 1][xx] == '.')
            if (cnt(yy + 1, xx) == 1)
                q.push(make_pair(yy + 1, xx));
    }

    if (kol < 0) fail();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%c", s[i][j]);
        printf("\n");
    }

    return 0;
}