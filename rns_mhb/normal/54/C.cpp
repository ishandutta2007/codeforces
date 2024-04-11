#include <bits/stdc++.h>
using namespace std;

#define N 1005

typedef long long ll;
typedef long double ld;
int n, k;
ll l[N], r[N];
ld p[N];
int c[N], cnt;
ll e[N], f[N];

void init() {
    e[0] = 1, f[0] = 1;
    for (int i = 1; i < 20; i ++) {
        e[i] = 10 * e[i-1];
        f[i] = 10 * f[i-1] + 1;
    }
}

ll calc(ll x) {
    if (!x) return 0;
    if (x == 1) return 1;
    ll nx = x;
    cnt = 0;
    while (x) {
        c[cnt++] = x % 10;
        x /= 10;
    }
    if (c[cnt-1] != 1) return f[cnt-1];
    else {
        return f[cnt-2] + nx - e[cnt-1] + 1;
    }
}

ld dp[N][N];

void calc_dp() {
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= n; j ++) {
        if (j > i) {
            dp[i][j] = 0;
            continue;
        }
        if (!j) {
            dp[i][j] = 1;
            continue;
        }
        dp[i][j] = p[i] * dp[i-1][j-1] + (1 - p[i]) * dp[i-1][j];
    }
}

int main() {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i ++) {
        scanf("%I64d %I64d", &l[i], &r[i]);
        p[i] = 1.0 * (calc(r[i]) - calc(l[i]-1)) / (r[i] - l[i] + 1);
    }
    scanf("%d", &k);
    calc_dp();
    printf("%.12lf\n", (double)dp[n][(int)ceil(1.0*n*k/100)]);
    return 0;
}