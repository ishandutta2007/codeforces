#include <bits/stdc++.h>
using namespace std;
#define N 5001
#define P 1000000007

int n, len = 0, f[N][N];
char c[N];


int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("\n%c", &c[i]);
    for (int i = 0; i < N; i ++) f[i][n-1] = 1;
    for (int i = n - 1; i > 0; i --) {
        int j;
        if (c[i-1] == 'f')
            for (j = 0; j < N - 1; j ++)
                f[j][i-1] = f[j+1][i];
        else
            for (j = 1, f[0][i-1] = f[0][i]; j < N; j ++)
                f[j][i-1] = (f[j-1][i-1] + f[j][i]) % P;
    }
    printf("%d\n", f[0][0]);

    return 0;
}