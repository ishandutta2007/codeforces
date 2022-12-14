#include <bits/stdc++.h>
using namespace std;
#define N 710

int gas[2][N], a[N][N];

int fab(int x) {
    return x < 0 ? -x:x;
}
int main() {
    int Q, n, m;
    int M = 256;
    for(scanf("%d", &Q); Q --;) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) scanf("%d", &a[i][j]);
        int nn = n / 2;
        int del = 5;
        int sum = 0;
        int sum1 = 0;
        for(int i = 1; i <= m; i ++) {
            sum += fab(a[nn][i] - a[nn + 1][i]);
            sum1 += fab(a[1][i] - a[n][i]);
        }
        if(sum >= sum1) puts("YES");
        else puts("NO");
    }
    return 0;
}