#include <bits/stdc++.h>
using namespace std;

#define N 333

int n, m, a[N][N];

void solve() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            int k = 4;
            if (i == 1 || i == n) k --;
            if (j == 1 || j == m) k --;
            if (a[i][j] > k) {
                puts("NO");
                return;
            }
            a[i][j] = k;
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) printf("%d ", a[i][j]);
        puts("");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) scanf("%d", &a[i][j]);
        solve();
    }

    return 0;
}