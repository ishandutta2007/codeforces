#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 512;

set <ll> s;
char a[N][N];
ll dp[N][N];
ll px[N][N], py[N][N];
ll ans;
int q, n, m, x1, y1, x2, y2;

int main() {
    //freopen("a.in", "r", stdin);

    scanf("%d%d ", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%c ", &a[i][j]);

    for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        if (i > 1 && a[i - 1][j - 1] == '.' && a[i - 2][j - 1] == '.') dp[i][j]++;
        if (j > 1 && a[i - 1][j - 1] == '.' && a[i - 1][j - 2] == '.') dp[i][j]++;
        //cerr << dp[i][j] << " ";
    }
        //cerr << "\n";
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++)
            py[i][j + 1] = py[i][j] + int(a[i - 1][j] == '.' && a[i][j] == '.');
    }
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++)
            px[i + 1][j] = px[i][j] + int(a[i][j - 1] == '.' && a[i][j] == '.');
    }

    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
        ans = dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
        if (x1 > 1)
            ans -= (px[y2][x1 - 1] - px[y1 - 1][x1 - 1]);
        if (y1 > 1)
            ans -= (py[y1 - 1][x2] - py[y1 - 1][x1 - 1]);
        printf("%I64d\n", ans);
    }



    return 0;
}