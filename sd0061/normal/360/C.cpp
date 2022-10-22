#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2005;
const int Q = 1e9 + 7;
int n , K;
char str[N];
int f[N][N] , g[N][N];

void work() {
    int i , j , k;
    scanf("%d%d%s" , &n , &K , str + 1);
    f[0][0] = g[0][0] = 1;
    for (i = 1 ; i <= n ; ++ i) {

        for (j = 0 ; j <= K ; ++ j) {
            f[i][j] = (LL) g[i - 1][j] * (str[i] - 'a') % Q;
            for (k = 1 ; k <= i && k * (n - i + 1) <= j ; ++ k) {
                f[i][j] += (LL) f[i - k][j - k * (n - i + 1)] * ('z' - str[i]) % Q;
                f[i][j] %= Q;
            }
            g[i][j] = (g[i - 1][j] + f[i][j]) % Q;
        }
    }
    int res = 0;
    for (i = 0 ; i <= n ; ++ i)
        res = (res + f[i][K]) % Q;
    printf("%d\n" , res);
}

int main() {
    work();
    return 0;
}