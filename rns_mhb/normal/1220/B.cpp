#include<bits/stdc++.h>
using namespace std;

#define N 1010

int a[N][N], b[N], n;

void check(int x) {
    b[1] = x;
    for(int i = 2; i <= n; i ++) {
        if(a[1][i] % x) return;
        b[i] = a[1][i] / x;
    }
    for(int i = 1; i <= n; i ++) for(int j = i + 1; j <= n; j ++) if(a[i][j] != 1ll*b[i]*b[j]) return;
    for(int i = 1; i <= n; i ++) printf("%d ", b[i]);
    exit(0);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) scanf("%d", &a[i][j]);
    int x = a[1][2];
    int D = sqrt(x + 1);
    for(int d = 1; d <= D; d ++) if(x % d == 0) {
        check(d);
        check(x/d);
    }
}