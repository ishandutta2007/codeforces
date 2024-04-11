#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105;
const int Q = 1e9 + 7;

int n , K;
LL m;

LL power(LL A , LL B) {
    LL I = 1;
    while (B) {
        if (B & 1)
            (I *= A) %= Q;
        (A *= A) %= Q , B >>= 1;
    }
    return I;
}
LL C[N][N];
LL f[N][N * N] , g[N][2];

void work() {
    int i , j , k;
    scanf("%d%lld%d" , &n , &m , &K);
    for (i = 0 ; i <= n ; ++ i) {
        C[i][0] = 1;
        for (j = 1 ; j <= i ; ++ j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Q;
    }
    LL x = m / n;
    for (i = 0 ; i <= n ; ++ i) {
        g[i][0] = power(C[n][i] , x);
        g[i][1] = g[i][0] * C[n][i] % Q;        
    }
    f[0][0] = 1;
    for (i = 0 ; i < n ; ++ i) {        
        bool v = (i < m % n);
        for (j = 0 ; j <= K ; ++ j) {
            if (!f[i][j]) continue;
            for (k = 0 ; k <= n && j + k <= K ; ++ k) {
                f[i + 1][j + k] += f[i][j] * g[k][v] % Q;
                f[i + 1][j + k] %= Q;
            }
        }
    }
    cout << f[n][K] << endl;
}

int main() {
    work();
    return 0;
}