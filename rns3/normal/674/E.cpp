#include <bits/stdc++.h>
using namespace std;
#define M 500500
const int U = 50;
double f[U + 5][M];
int n, query;
int fa[M];
double inv2[100], t[100];
int sz[M];

double calc(int x) {
    double rlt = 0;
    for (int i = 1; i <= U; i++) {
        rlt += i * (f[i][x] - f[i-1][x]);
        //printf("i = %d, %.3lf, %.3lf\n", i, f[i][x] - f[i-1][x], i * (f[i][x] - f[i-1][x]));
    }
    return rlt;
}

void create(int x) {
    for (int i = 0; i <= U; i++) {
        f[i][x] = 1;
        //printf("f[%d][%d] = %.3lf\n", i, x, f[i][x]);
    }
}

void init() {
    inv2[0] = 1.;
    for (int i = 1; i < 100; i++) inv2[i] = inv2[i-1] / 2.;
}

void update(int x, int p) {
    fa[x] = p;
    ++sz[p];
    x = p;
    double g;
    t[0] = 1;
    for (int i = 1; i <= U && x; i++, x = fa[x]) {
        for (int a = i; a >= 1; a--) {
            g = f[a][x] * t[a-1];
            t[a] = (1 + g) / (1 + f[a][x]);
            f[a][x] = g;
            //printf("f[%d][%d] = %.3lf\n", a, x, f[a][x]);
        }
        if (sz[x] >= U) {
            g = 0;
        } else {
            //printf("sz[%d] = %d\n", x, sz[x]);
            g = inv2[sz[x]];
        }
        t[0] = (1 + g) / (1 + f[0][x]);
        f[0][x] = g;
        //int a = 0;
        //printf("f[%d][%d] = %.3lf\n", a, x, f[a][x]);
    }
}

int main() {
    scanf("%d", &query);
    init();
    n = 1;
    create(1);
    for (int type, x; query--; ) {
        scanf("%d", &type);
        scanf("%d", &x);
        if (type == 1) {
            ++n;
            create(n);
            update(n, x);
        } else {
            printf("%.10lf\n", calc(x));
        }
    }
    return 0;
}