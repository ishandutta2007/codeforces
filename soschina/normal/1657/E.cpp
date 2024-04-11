#include <cstdio>
using namespace std;
const int N = 251, p = 998244353;

int fpow(int base, int t){
    int ret = 1;
    while(t){
        if(t & 1) ret = 1ll * ret * base % p;
        base = 1ll * base * base % p;
        t >>= 1;
    }
    return ret;
}

int n, m, f[N][N], C[N][N];

int main(){
    scanf("%d%d", &n, &m);
    n--;
    C[0][0] = 1;
    for(int i = 1; i <= n; i++){
        C[i][0] = 1;
        for(int j = 1; j <= n; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
    }
    f[0][0] = 1;
    for(int j = 1; j <= m; j++){
        f[0][j] = 1;
        for(int i = 1; i <= n; i++)
            for(int k = 0; k <= i; k++)
                f[i][j] = (f[i][j] + 1ll * f[i - k][j - 1] * C[i][k] % p * fpow(m - j + 1, k * (i - 1) - k * (k - 1) / 2) % p) % p;
    }
    printf("%d", f[n][m]);
    return 0;
}