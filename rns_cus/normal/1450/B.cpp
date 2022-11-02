#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, x[N], y[N], K;

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &K);
        for (int i = 1; i <= n; i ++) scanf("%d %d", &x[i], &y[i]);
        bool ok = false;
        for (int i = 1; i <= n; i ++) {
            bool fg = true;
            for (int j = 1; j <= n; j ++) if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > K) fg = false;
            if (fg) ok = true;
        }
        if (ok) puts("1");
        else puts("-1");
    }


    return 0;
}