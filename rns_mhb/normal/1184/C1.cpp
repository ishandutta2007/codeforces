#include<bits/stdc++.h>
using namespace std;

const int K = 50;

int n, m, x[K], y[K];

void solve(int a, int b, int r) {
    if(a + r > K || b + r > K) return;
    int L = 0, R = 0, D = 0, U = 0, ax = -1, ay = -1;
    for(int i = 1; i <= m; i ++) {
        bool flag = 0;
        if(x[i] == a && b <= y[i] && y[i] <= b+r) L ++, flag = 1;
        if(x[i] == a+r && b <= y[i] && y[i] <= b+r) R ++, flag = 1;
        if(y[i] == b && a <= x[i] && x[i] <= a+r) D ++, flag = 1;
        if(y[i] == b+r && a <= x[i] && x[i] <= a+r) U ++, flag = 1;
        if(flag) continue;
        if(ax == -1 && ay == -1) ax = x[i], ay = y[i];
        else return;
    }
    if(L < n || R < n || D < n || U < n) return;
    printf("%d %d\n", ax, ay);
    exit(0);
}

int main() {
    scanf("%d", &n);
    m = 4*n + 1;
    for(int i = 1; i <= m; i ++) scanf("%d%d", &x[i], &y[i]);
    for(int i = 0; i <= K; i ++) for(int j = 0; j <= K; j ++) for(int r = 1; r <= K; r ++) solve(i, j, r);
}