#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
int d[N][N][4];
int mv[N][N];
string a[N];
char ss[N];

struct tri {
    int x, y, r;
    tri() {}
    tri(int xx, int yy, int rr) {
        x = xx;
        y = yy;
        r = rr;
    }
};

bool check(int x, int p) {
    return (x & (1 << p));
}

int n, m, xf, yf, xs, ys, x, y, r;
char ch;

int main() {
    //freopen("a.in", "r", stdin);

    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        gets(ss);
        a[i] = ss;
    }
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        ch = a[i][j];
        if (ch == '+') mv[i][j] = 15;
        if (ch == '-') mv[i][j] = 5;
        if (ch == '|') mv[i][j] = 10;
        if (ch == '^') mv[i][j] = 2;
        if (ch == 'v') mv[i][j] = 8;
        if (ch == '>') mv[i][j] = 1;
        if (ch == '<') mv[i][j] = 4;
        if (ch == 'L') mv[i][j] = 11;
        if (ch == 'R') mv[i][j] = 14;
        if (ch == 'U') mv[i][j] = 13;
        if (ch == 'D') mv[i][j] = 7;
        d[i][j][0] = d[i][j][1] = d[i][j][2] = d[i][j][3] = -1;
    }
    scanf("%d%d%d%d", &ys, &xs, &yf, &xf);

    queue <tri> q;
    q.push(tri(xs - 1, ys - 1, 0));
    d[ys - 1][xs - 1][0] = 0;

    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        r = q.front().r;
        q.pop();

        if (d[y][x][(r + 1) & 3] == -1) {
            d[y][x][(r + 1) & 3] = d[y][x][r] + 1;
            q.push(tri(x, y, (r + 1) & 3));
        }

        if (x + 1 < m && d[y][x + 1][r] == -1 && check(mv[y][x], r) && check(mv[y][x + 1], (r + 2) & 3)) {
            d[y][x + 1][r] = d[y][x][r] + 1;
            q.push(tri(x + 1, y, r));
        }

        if (x > 0 && d[y][x - 1][r] == -1 && check(mv[y][x], (r + 2) & 3) && check(mv[y][x - 1], r)) {
            d[y][x - 1][r] = d[y][x][r] + 1;
            q.push(tri(x - 1, y, r));
        }

        if (y + 1 < n && d[y + 1][x][r] == -1 && check(mv[y][x], (r + 3) & 3) && check(mv[y + 1][x], (r + 1) & 3)) {
            d[y + 1][x][r] = d[y][x][r] + 1;
            q.push(tri(x, y + 1, r));
        }

        if (y > 0 && d[y - 1][x][r] == -1 && check(mv[y][x], (r + 1) & 3) && check(mv[y - 1][x], (r + 3) & 3)) {
            d[y - 1][x][r] = d[y][x][r] + 1;
            q.push(tri(x, y - 1, r));
        }
    }

    yf--;
    xf--;
    int ans = d[yf][xf][0];
    for (int i = 1; i < 4; i++) {
        if (ans == -1 || (ans > d[yf][xf][i] && d[yf][xf][i] != -1))
            ans = d[yf][xf][i];
    }
    printf("%d\n", ans);

    return 0;
}