#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

#define N 2005
int n , m , K;
int p[N][N] , C[N][N] , f[N];
int Q = 1000000007;

void work()
{
    int i , j;
    p[0][0] = 1;
    for (i = 1 ; i <= 2000 ; ++ i)
        for (j = 1 ; j <= i ; ++ j) {
            p[i][j] = p[i - j][j] + p[i - j][j - 1];
            p[i][j] %= Q;
    }
    for (i = 0 ; i <= 2000 ; ++ i) {
        C[i][0] = 1;
        for (j = 1 ; j <= 2000 ; ++ j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= Q;
        }
    }
    f[0] = 1;
    for (i = 1 ; i <= 1000 ; ++ i) {
        f[i] = (long long)f[i - 1] * i % Q;
    }
    scanf("%d",&m);
    while (m --) {
        scanf("%d%d",&n,&K);
        int res = 0;
        for (i = K * (K - 1) / 2 ; i + K <= n ; ++ i) {
            res += (long long) p[i + K][K] * C[n - i][K] % Q;
            res %= Q;
        }
        printf("%I64d\n" , (long long)res * f[K] % Q);
    }

}

int main()
{
    work();
    return 0;
}