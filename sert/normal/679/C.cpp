#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 505;

int n, k;
char ss[N];
int u[N * N];
int c[N][N], kmp;
int sz[N * N];
int p[N][N];
int cur, mx;

void dfs(int y, int x) {
    if (c[y][x] != -2)
        return;
    c[y][x] = kmp;
    sz[kmp]++;
    if (x > 0 && c[y][x - 1] == -2)
        dfs(y, x - 1);
    if (y > 0 && c[y - 1][x] == -2)
        dfs(y - 1, x);
    if (y + 1 < n && c[y + 1][x] == -2)
        dfs(y + 1, x);
    if (x + 1 < n && c[y][x + 1] == -2)
        dfs(y, x + 1);
}

void relax(int y, int x) {
    mx = max(mx, cur + p[y + k][x + k] - p[y][x + k] - p[y + k][x] + p[y][x]);
}

void rem(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= n) return;
    int tmp = c[y][x];
    if (tmp >= 0) {
        u[tmp]--;
        if (u[tmp] == 0)
            cur -= sz[tmp];
    }
}

void add(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= n) return;
    int tmp = c[y][x];
    if (tmp >= 0) {
        if (u[tmp] == 0)
            cur += sz[tmp];
        u[tmp]++;
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d %d\n", &n, &k);
    for (int i = 0; i < n; i++) {
        gets(ss);
        for (int j = 0; j < n; j++) {
            c[i][j] = (ss[j] == '.' ? -2 : -1);
            if (c[i][j] == -1)
                p[i + 1][j + 1] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            p[i][j] = p[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];

    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        if (c[i][j] == -2) {
            dfs(i, j);
            kmp++;
        }
    }

    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j < kmp; j++)
            u[j] = 0;
        cur = 0;

        for (int ii = i - 1; ii <= i + k; ii++)
            if (ii >= 0 && ii < n)
                for (int jj = 0; jj < k; jj++) {
                    add(ii, jj);
                }

        if (k < n)
            for (int ii = i; ii < i + k; ii++) {
                add(ii, k);
            }

        relax(i, 0);

        for (int j = 1; j <= n - k; j++) {
            for (int ii = i; ii < i + k; ii++) {
                rem(ii, j - 2);
                add(ii, j + k);
            }
            rem(i - 1, j - 1);
            rem(i + k, j - 1);
            add(i - 1, j + k - 1);
            add(i + k, j + k - 1);
            relax(i, j);
        }
    }

    cout << mx;

    return 0;
}