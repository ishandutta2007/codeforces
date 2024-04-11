#include <iostream>
using namespace std;

int n, m, k;
int a[202][202], sum[202];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            scanf("%d", &a[i][j]);
        }
    }

    int ans = 0, res = 0;
    for (int j = 1; j <= m; j ++) {
        for (int i = 1; i <= n; i ++) {
            sum[i] = sum[i-1] + a[i][j];
        }

        int best = 0, cnt = 0, best_cnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (a[i][j]) {
                int tmp = sum[min(i + k - 1, n)] - sum[i - 1];
                if (tmp > best) {
                    best = tmp;
                    best_cnt = cnt;
                } 
                cnt ++;
            }
        }
        ans += best;
        res += best_cnt;
    }
    printf("%d %d\n", ans, res);
}