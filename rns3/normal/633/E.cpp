#include <bits/stdc++.h>
using namespace std;

#define M 1001001

int n;
int v[M], c[M];
int mxv[20][M], mnc[20][M];
int f[M];

main() {
    //freopen("E.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    //for (int i = 1; i <= n; i++) fac[i] = fac[i-1] * i;
    for (int i = 1; i <= n; i ++) scanf("%d", v + i), v[i] *= 100, mxv[0][i] = v[i];
    for (int i = 1; i <= n; i ++) scanf("%d", c + i), mnc[0][i] = c[i];

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j + (1<<i) - 1 <= n; j++) {
            mxv[i][j] = max(mxv[i-1][j], mxv[i-1][j + (1<<(i-1))]);
            mnc[i][j] = min(mnc[i-1][j], mnc[i-1][j + (1<<(i-1))]);
        }
    }

    for (int l = 1; l <= n; l++) {
        f[l] = min(v[l], c[l]);
        if (l == n) {
            continue;
        }

        int x = l;
        int V = v[l], C = c[l];
        for (int i = 19; i >= 0; i--) if ((x + (1<<i) - 1) <= n){
            int VV = max(V, mxv[i][x]);
            int CC = min(C, mnc[i][x]);
            if (VV > CC) {
                continue;
            }
            V = VV, C = CC;
            f[l] = max(f[l], VV);
            x += (1<<i);
        }
        //printf("l = %d, x = %d;v = %d, c = %d\n", l, x, V, C);
        if (x <= n) {
            V = max(V, v[x]);
            C = min(C, c[x]);
            f[l] = max(f[l], min(V, C));
        }
    }
    for (int l = 1; l <= n; l++) {
        //printf("f[%d] = %d\n", l, f[l]);
    }

    double answer = 0;
    sort(f + 1, f + n + 1);
    reverse(f + 1, f + n + 1);
    double c = 1. * m / n;
    for (int i = n; i >= m; i--) {
        if (i < n) {
            c = 1. * c * (i - m + 1) / i;
        }
        answer += f[i] * c;
        //c *= 1. * t / (t - m + 1);
        //answer += f[i] * fac[i-1] / fac[m-1] / fac[i-m];
    }
    printf("%.10lf\n", answer);
    return 0;
}