#include<bits/stdc++.h>
using namespace std;

#define N 2010
int a[N][N], b[N][N], w[N][N];

int main() {
    int n, i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) for(j = 1; j <= n; j ++) scanf("%d", w[i] + j);
    for(i = 1; i <= n; i ++) for(j = 1; j <= n; j ++) {
        a[i][j] = w[i][j] + w[j][i];
        b[i][j] = w[i][j] - w[j][i];
    }
    for(i = 1; i <= n; i ++) {
        printf("%.7lf", a[i][1] / 2.0);
        for(j = 2; j <= n; j ++) printf(" %.7lf", a[i][j] / 2.0);
        puts("");
    }
    for(i = 1; i <= n; i ++) {
        printf("%.7lf", b[i][1] / 2.0);
        for(j = 2; j <= n; j ++) printf(" %.7lf", b[i][j] / 2.0);
        puts("");
    }
}