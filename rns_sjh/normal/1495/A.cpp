#include<bits/stdc++.h>
using namespace std;

#define N 100010

int t, n, x[N], y[N];

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d", &n);
        int l = 0, k = 0;
        for(int i = 1; i <= 2 * n; i ++) {
            scanf("%d%d", &x[0], &y[0]);
            if(x[0] == 0) y[++ l] = y[0];
            else x[++ k] = x[0];
        }
        for(int i = 1; i <= n; i ++) x[i] = abs(x[i]), y[i] = abs(y[i]);
        sort(x + 1, x + n + 1);
        sort(y + 1, y + n + 1);
        double ans = 0;
        for(int i = 1; i <= n; i ++) ans += sqrt(1ll * x[i] * x[i] + 1ll * y[i] * y[i]);
        printf("%.15f\n", ans);
    }
}