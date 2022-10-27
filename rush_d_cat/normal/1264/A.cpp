#include <iostream>
using namespace std;
const int N = 400000 + 10;
int t, n, p[N];
int cnt, a[N], sum[N];
int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &p[i]);
        }
        cnt = 0;
        for (int i = 1, j = i; i <= n; i = j) {
            while (j <= n && p[j] == p[i]) ++ j;
            a[++cnt] = j - i;
        } 

        int g = a[1], s = -1, b = -1;
        for (int i = 1; i <= cnt; i ++) {
            sum[i] = sum[i-1] + a[i];
        }

        int laspos = 0;
        for (int i = 1; i <= cnt; i ++) {
            if (sum[i] * 2 <= sum[cnt]) laspos = i;
        }

        bool ok = 0;
        for (int j = 2; j < cnt-1; j ++) {
            //printf("%d %d\n", sum[j]-sum[1], sum[cnt-1]-sum[j]);
            if (sum[j] - sum[1] > a[1] && sum[laspos] - sum[j] > a[1]) {
                ok = 1;
                printf("%d %d %d\n", a[1], sum[j] - sum[1], sum[laspos] - sum[j]);
                break;
            }
        }
        if (ok == 0) {
            printf("%d %d %d\n", 0, 0, 0);
        }
    }
}