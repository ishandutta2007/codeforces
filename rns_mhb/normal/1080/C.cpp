#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t, n, m, x[4], y[4];
ll cnt[4][2];

void calc(int x, int y, int fg, ll *c) {
    x = max(0, x + 1), y = max(0, y + 1);
    c[0] = c[1] = 1ll * x * y / 2;
    if (x & y & 1) c[fg] ++;
}

int len(int *x) {
    return min(x[1], x[3]) - max(x[0], x[2]);
}

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < 4; i ++) scanf("%d %d", &x[i], &y[i]);
        calc(m - 1, n - 1, 0, cnt[0]);
        calc(x[1] - x[0], y[1] - y[0], (x[0] ^ y[0]) & 1, cnt[1]);
        calc(x[3] - x[2], y[3] - y[2], (x[2] ^ y[2]) & 1, cnt[2]);
        calc(len(x), len(y), (max(x[0], x[2]) ^ max(y[0], y[2])) & 1, cnt[3]);
        printf("%I64d %I64d\n", cnt[0][0] + cnt[1][1] - cnt[3][1] - cnt[2][0], cnt[0][1] - cnt[1][1] + cnt[3][1] + cnt[2][0]);
    }
}