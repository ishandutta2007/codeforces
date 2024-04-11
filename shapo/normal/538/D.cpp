#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

const int MAXN = 100;

bool used[MAXN][MAXN];
bool checked[MAXN][MAXN];
bool beat[MAXN][MAXN];
int n;
bool ok;
char ans[2 * MAXN][2 * MAXN];

inline bool
in_border(int x, int y, int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool
check(int dx, int dy)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!used[i][j]) {
                continue;
            }
            int cx = i + dx, cy = j + dy;
            if (in_border(cx, cy, n) && !beat[cx][cy] && !used[cx][cy]) {
                return false;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!used[i][j]) {
                continue;
            }
            int cx = i + dx, cy = j + dy;
            if (in_border(cx, cy, n)) {
                checked[cx][cy] = true;
            }
        }
    }
    return true;
}

int
main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char buf[100];
        scanf(" %s", buf);
        for (int j = 0; j < n; ++j) {
            used[i][j] = (buf[j] == 'o');
            beat[i][j] = (buf[j] == 'x');
        }
    }
    ok = true;
    for (int dx = 1 - n; dx <= n - 1; ++dx) {
        for (int dy = 1 - n; dy <= n - 1; ++dy) {
            ans[dx + n - 1][dy + n - 1] = (check(dx, dy)) ? 'x' : '.';
        }
    }
    ans[n - 1][n - 1] = 'o';
    for (int i = 0; ok && i < n; ++i) {
        for (int j = 0; ok && j < n; ++j) {
            if (beat[i][j] && !checked[i][j]) {
                ok = false;
            }
        }
    }
    if (!ok) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0; i < 2 * n - 1; ++i) {
            ans[i][2 * n - 1] = 0;
            puts(ans[i]);
        }
    }
    return 0;
}