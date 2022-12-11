#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1003;
char a[N][N];
int c[N][N];
int ans[N * N];
int cnt(int y, int x) {
    return int(a[y][x - 1] == '*') + int(a[y][x + 1] == '*') + int(a[y - 1][x] == '*') + int(a[y + 1][x] == '*');
}
void dfs(int y, int x, int cp) {
    if (a[y][x] != '.')
        return;
    a[y][x] = '@';
    c[y][x] = cp;
    ans[cp] += cnt(y, x);
    dfs(y - 1, x, cp);
    dfs(y + 1, x, cp);
    dfs(y, x - 1, cp);
    dfs(y, x + 1, cp);
}
int n, m, k, cmp, x, y;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%c ", a[i] + j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '.')
                dfs(i, j, cmp++);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &y, &x);
        printf("%d\n", ans[c[y - 1][x - 1]]);
    }


    return 0;
}