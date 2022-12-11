#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef long double ld;

int n, m, k;

char a[400][400];

bool is(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) return false;
    return a[y][x] == '*';
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int r = 1; r <= min(n, m) / 2; r++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (!is(j, i)) continue;
                if (!is(j + r, i)) continue;
                if (!is(j - r, i)) continue;
                if (!is(j, i - r)) continue;
                if (!is(j, i + r)) continue;
                k--;
                if (!k) {
                    printf("%d %d\n", i + 1, j + 1);
                    printf("%d %d\n", i + 1 - r, j + 1);
                    printf("%d %d\n", i + 1 + r, j + 1);
                    printf("%d %d\n", i + 1, j + 1 - r);
                    printf("%d %d\n", i + 1, j + 1 + r);
                    return 0;
                }
            }
    printf("-1\n");

    return 0;
}