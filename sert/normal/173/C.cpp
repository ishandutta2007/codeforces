#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 503;

int a[N][N];
int r[N][N], c[N][N];
int ans = -100000, cur, x, y, tmp, n, m, xx, yy;
int u[N][N];

void addh(int y0, int x1, int x2) {
    if (x1 > x2) swap(x1, x2);
    tmp = r[y0][x2 + 1] - r[y0][x1];
    cur += tmp;
}

void addv(int x0, int y1, int y2) {
    if (y1 > y2) swap(y1, y2);
    tmp = c[x0][y2 + 1] - c[x0][y1];
    cur += tmp;
}

void relax() {
    if (cur > ans)
        ans = cur;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", a[i] + j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            r[i][j + 1] = r[i][j] + a[i][j];
            c[j][i + 1] = c[j][i] + a[i][j];
        }
    int r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i - 2 >= 0 && j + 2 < m) {
                x = j;
                y = i - 2;
                cur = 0;
                addh(i, j, j + 2);
                addv(j + 2, i - 1, i - 2);
                addh(i - 2, j + 1, j);
                relax();
                r = 4;
                while (x > 1 && y > 1 && x + r < m && y + r < n) {
                    addh(y, x - 1, x - 2);
                    addv(x - 2, y + 1, y + r);
                    addh(y + r, x - 1, x + r);
                    addv(x + r, y + r - 1, y - 2);
                    addh(y - 2, x + r - 1, x - 2);
                    relax();
                    r += 4;
                    x -= 2;
                    y -= 2;
                }
            }
            if (i - 2 >= 0 && i + 2 < n && j - 2 >= 0 && j + 2 < m) {
                y = i - 2;
                x = j - 2;
                cur = 0;
                addh(i, j, j - 2);
                addv(j - 2, i + 1, i + 2);
                addh(i + 2, j - 1, j + 2);
                addv(j + 2, i + 1, i - 2);
                addh(i - 2, j + 1, j - 2);
                relax();
                r = 6;
                while (x > 1 && y > 1 && x + r < m && y + r < n) {
                    addh(y, x - 1, x - 2);
                    addv(x - 2, y + 1, y + r);
                    addh(y + r, x - 1, x + r);
                    addv(x + r, y + r - 1, y - 2);
                    addh(y - 2, x + r - 1, x - 2);
                    relax();
                    r += 4;
                    x -= 2;
                    y -= 2;
                }
            }
        }
    printf("%d\n", ans);

    return 0;
}