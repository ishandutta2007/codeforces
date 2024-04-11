#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

#define N 100010
#define K 201

int n, a[N], f[N][K], g[N][K];

void add(int &x, int y) {x += y; if(x >= mod) x -= mod;}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    if(a[1] == -1) {
        for(int i = 2; i < K; i ++) f[1][i] = 1;
        g[1][1] = 1;
    }
    else {
        f[1][a[1]] = 1;
        if(a[1] == 1) g[1][1] = 1, f[1][1] = 0;
    }
    for(int i = 2; i <= n; i ++) {
        int sum = 0;
        for(int j = 1; j < K; j ++) {
            add(sum, f[i-1][j-1]);
            add(sum, g[i-1][j-1]);
            if(a[i] == -1 || a[i] == j) f[i][j] = sum;
        }
        sum = 0;
        for(int j = K-1; j; j --) {
            add(sum, g[i-1][j]);
            if(a[i] == -1 || a[i] == j) {
                g[i][j] = sum + f[i-1][j];
                if(g[i][j] >= mod) g[i][j] -= mod;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < K; i ++) add(ans, g[n][i]);
    printf("%d\n", ans);
}