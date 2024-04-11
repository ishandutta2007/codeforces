#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 111;
const int INF = 1111111;
int n, m, k, a[N][N], b[N][N];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            b[i][j] = a[i][j];
        }
    if (n < m) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                a[j][i] = b[i][j];
        swap(n, m);
    }
    int ans = INF;
    if (n > k) {
        for(int i = 1; i <= n; i++) {
            int tmp = 0;
            for(int j = 1; j <= n; j++)
                if (i != j) {
                    int res = 0;
                    for(int p = 1; p <= m; p++) {
                        if (a[j][p] != a[i][p])
                            res++;
                    }
                    tmp += min(res, m - res);
                }
            ans = min(ans, tmp);
        }
    } else {
        for(int msk = 0; msk < (1 << m); msk++) {
            int tmp = 0;
            for(int i = 1; i <= n; i++) {
                int res = 0;
                for(int j = 1; j <= m; j++) {
                    int c = (msk >> (j - 1) & 1);
                    if (c != a[i][j])
                        res++;
                }
                tmp += min(res, m - res);
            }
            ans = min(ans, tmp);
        }
    }
    printf("%d\n", ans > k ? -1 : ans);
    return 0;
}