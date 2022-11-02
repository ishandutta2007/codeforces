#include <bits/stdc++.h>
using namespace std;

const int M = 131;

double pw[32][M][M];
double p[M], q[M][M];

void multi(double a[][M], double b[][M], double c[][M]) {
    for(int i = 0; i < M; i ++) {
        for(int j = 0; j < M; j ++) {
            c[i][j] = 0;
            for(int k = 0; k < M; k ++) c[i][j] += a[i][k] * b[k][j];
        }
    }
}

double ans[M][M], res[M][M];

int main() {
    ///freopen("d.in", "r", stdin);
    int n, x;
    scanf("%d %d", &n, &x);
    n --;
    for(int i = 0; i <= x; i ++) scanf("%lf", &p[i]);
    x = 127;
    for(int i = 0; i <= x; i ++) {
        for(int j = 0; j <= x; j ++) {
            pw[0][i][j] = p[i^j];
        }
    }
    for(int i = 1; i <= 30; i ++) {
        multi(pw[i-1], pw[i-1], pw[i]);
    }
    for(int i = 0; i <= x; i ++) for(int j = 0; j <= x; j ++) {
        if(i == j) ans[i][j] = 1;
        else ans[i][j] = 0;
    }
    for(int i = 0; i <= 30; i ++) if(n & (1<<i)) {
        multi(ans, pw[i], res);
        memcpy(ans, res, sizeof(ans));
    }
    double ANS = 0;
    for(int i = 0; i <= x; i ++) ANS += p[i] * ans[i][0];
    printf("%.30lf\n", 1 - ANS);
}