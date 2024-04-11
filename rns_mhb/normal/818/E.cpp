#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define M 15

typedef long long ll;
int n, k, cnt;
int p[M], al[M], now[M], c[M];
int b[M][N];
ll ans;

int main () {
    scanf("%d %d", &n, &k);
    if (k == 1) return printf("%I64d\n", 1ll * n * (n + 1) / 2), 0;
    int cur = 2;
    while (k > 1) {
        bool fg = 0;
        for (; cur * cur <= k && !fg; cur ++) {
            if (k % cur == 0) {
                p[cnt] = cur;
                while (k % cur == 0) k /= cur, al[cnt] ++;
                cnt ++;
                fg = 1;
            }
        }
        if (!fg) p[cnt] = k, al[cnt++] ++, k = 1;
    }
    for (int i = 1, x, mn; i <= n; i ++) {
        scanf("%d", &x);
        mn = n + 1;
        for (int j = 0; j < cnt; j ++) {
            while (x % p[j] == 0) x /= p[j], b[j][i] ++;
            c[j] += b[j][i];
            while (c[j] - b[j][now[j]+1] >= al[j] && now[j] < i) c[j] -= b[j][++now[j]];
            mn = min(mn, now[j]);
            if (c[j] < al[j]) mn = -1;
        }
        ans += mn + 1;
    }
    printf("%I64d\n", ans);
    return 0;
}