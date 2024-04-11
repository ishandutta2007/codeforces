#include <bits/stdc++.h>

const int max_N = 500 + 21;

int n, m, a[max_N][max_N], Q[max_N][max_N], ans1, ans2;

int main() {
    scanf("%d%d", &n, &m);
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a[i] + j);
        }
    }
    ans1 = 0x3f3f3f3f;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            Q[i][j] = j;
        }
        std::sort(Q[i] + 1, Q[i] + 1 + m, [&](int x, int y) { return a[i][x] - a[n][x] > a[i][y] - a[n][y]; });
        int sum = 0, cur = 0;
        while (cur < m) {
            int x = Q[i][cur + 1];
            sum += a[i][x] - a[n][x];
            if (sum < 0) {
                break;
            }
            ++cur;
        }
        if (ans1 > m - cur) {
            ans1 = m - cur;
            ans2 = i;
        }
    }
    printf("%d\n", ans1);
    for (int i = 0; i < ans1; ++i) {
        printf("%d%c", Q[ans2][m - i], " \n"[i == ans1 - 1]);
    }
}
/*
 5 3
 6 3 4 2 8
 3 7 5 6 7
 5 2 4 7 9

 2 1
 1 1
 
 3 3
 2 3 8
 4 2 9
 3 1 7
 */