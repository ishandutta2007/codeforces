#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define N 360360
LL a, b;
int f[N + 1], g[N + 1];
int k;

LL run() {
    if(k == 2) return b - a;
    if(a == b) return 0;
    for(int i = 1; i <= N; i ++) {
        f[i] = f[i-1] + 1;
        for(int j = 3; j <= k; j ++) {
            f[i] = min(f[i], f[i / j * j] + 1);
        }
    }
    int t = a % N;
    g[t] = 0;
    for(int i = t + 1; i <= N; i ++) {
        g[i] = g[i-1] + 1;
        for(int j = 3; j <= k; j ++) {
            int tt = i / j * j;
            if(tt >= t) g[i] = min(g[i], g[tt] + 1);
        }
    }
    if(((a / N) + 1) * N >= b) {
        t = b % N;
        if(t == 0) t = N;
        return g[t];
    }
    LL rt = g[N] + f[b % N] + 1LL * (b / N - 1 - a / N) * f[N];
    return rt;
}

int main() {
    scanf("%I64d%I64d%d", &b, &a, &k);
    printf("%I64d\n", run());
    return 0;
}