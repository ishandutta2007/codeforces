#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int test;
int n, m;

int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

char a[300][300];
int used[300][300];

bool val(int x, int y) {return (0 <= x && x < n && 0 <= y && y < m);}

bool check(int x, int y)
{
    for (int i = 0; i < 8; i ++)
        if (val(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == '1' && used[x + dx[i]][y + dy[i]] != used[x][y])
            return false;
    return true;
}

void solve()
{
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i ++)
        gets(a[i]);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            used[i][j] = false;

    int res = 0;
    int f = 0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if (!used[i][j] && a[i][j] == '1')
            {
                f ++;
                int r = j, d = i;
                while (r < m && a[i][r] == '1') used[i][r] = f, r ++;
                r --;
                while (d < n && a[d][j] == '1') used[d][j] = f, d ++;
                d --;

                if (r - j != d - i) continue;
                if (r == j) continue;

                int r1 = j, d1 = i;
                while (r1 < m && a[d][r1] == '1') used[d][r1] = f, r1 ++;
                r1 --;
                while (d1 < n && a[d1][r] == '1') used[d1][r] = f, d1 ++;
                d1 --;

                if (r1 != r) continue;
                if (d1 != d) continue;

                bool good = true;
                for (int k = j; k <= r; k ++)
                    if (!check(i, k) || !check(d, k)) {good = false; break;}
                if (!good) continue;

                for (int k = i; k <= d; k ++)
                    if (!check(k, j) || !check(k, r)) {good = false; break;}
                if (!good) continue;

                res ++;

                /*f ++;
                int r = j, d = j;
                while (r < m && a[i][r] == '1') used[i][r] = f, r ++;
                r --;
                int d1 = i, d2 = i;
                while (d1 < n && a[d1][j] == '1') d1 ++;
                while (d2 < n && a[d2][r] == '1') d2 ++;
                d1 --, d2 --;
                for (int k = j; k <= r; k ++)
                    used[i][k] = true;
                for (int k = i; k <= d1; k ++)
                    used[k][j] = true;
                for (int k = i; k <= d2; k ++)
                    used[k][r] = true;
                if (d1 != d2) continue;

                bool good = true;
                for (int k = j; k <= r; k ++)
                    if (a[d1][k] != '1') {good = false; break;}
                if (!good) continue;

                for (int k = j; k <= r; k ++)
                    used[d1][k] = true;

                if (r - j + 1 != d1 - i + 1) continue;

                good = true;

                for (int k = j; k <= r; k ++)
                    if (val(i - 1, k) && a[i - 1][k] == '1') {good = false; break;}
                if (!good) continue;

                for (int k = j; k <= r; k ++)
                    if (val(d1 + 1, k) && a[d1 + 1][k] == '1') {good = false; break;}
                if (!good) continue;

                for (int k = i; k <= d1; k ++)
                    if (val(k, j - 1) && a[k][j - 1] == '1') {good = false; break;}
                if (!good) continue;

                for (int k = i; k <= d1; k ++)
                    if (val(k, r + 1) && a[k][r + 1] == '1') {good = false; break;}
                if (!good) continue;

                if (val(i - 1, j - 1) && a[i - 1][j - 1] == '1') good = false;
                if (val(i - 1, r + 1) && a[i - 1][r + 1] == '1') good = false;
                if (val(d1 + 1, j - 1) && a[d1 + 1][j - 1] == '1') good = false;
                if (val(d1 + 1, r + 1) && a[d1 + 1][r + 1] == '1') good = false;

                if (!good) continue;

                if (r == j + 1) {res ++; continue;}

                for (int k = j + 1; k < r; k ++)
                    if (val(i + 1, k) && a[i + 1][k] == '1') {good = false; break;}
                if (!good) continue;

                for (int k = j + 1; k < r; k ++)
                    if (val(d1 - 1, k) && a[d1 - 1][k] == '1') {good = false; break;}
                if (!good) continue;

                for (int k = i + 1; k < d1; k ++)
                    if (val(k, j + 1) && a[k][j + 1] == '1') {good = false; break;}
                if (!good) continue;

                for (int k = i + 1; k < d1; k ++)
                    if (val(k, r - 1) && a[k][r - 1] == '1') {good = false; break;}
                if (!good) continue;*/
            }

    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            used[i][j] = false;

    f = 0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if (!used[i][j] && a[i][j] == '1')
            {
                f ++;
                int rx = i, ry = j, lx = i, ly = j, dx1, dy1, dx2, dy2;
                while (val(rx, ry) && a[rx][ry] == '1') used[rx][ry] = f, rx ++, ry ++;
                rx --, ry --;
                while (val(lx, ly) && a[lx][ly] == '1') used[lx][ly] = f, lx ++, ly --;
                lx --, ly ++;

                if (lx != rx) continue;
                if (lx == i) continue;
                dx1 = lx, dy1 = ly;
                while (val(dx1, dy1) && a[dx1][dy1] == '1') used[dx1][dy1] = f, dx1 ++, dy1 ++;
                dx1 --, dy1 --;

                dx2 = rx, dy2 = ry;
                while (val(dx2, dy2) && a[dx2][dy2] == '1') used[dx2][dy2] = f, dx2 ++, dy2 --;
                dx2 --, dy2 ++;

                if (dx1 != dx2) continue;
                if (dy1 != dy2) continue;

                bool good = true;
                for (int k = i; k <= rx; k ++)
                    if (!check(k, j + k - i)) {good = false; break;}
                if (!good) continue;

                for (int k = i; k <= lx; k ++)
                    if (!check(k, j - k + i)) {good = false; break;}
                if (!good) continue;

                for (int k = lx; k <= dx1; k ++)
                    if (!check(k, ly + k - lx)) {good = false; break;}
                if (!good) continue;

                for (int k = rx; k <= dx1; k ++)
                    if (!check(k, ry - k + rx)) {good = false; break;}
                if (!good) continue;
                res ++;
            }

    printf("%d\n", res);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d\n", &test);
    for (int it = 1; it <= test; it ++)
        solve();
    return 0;
}