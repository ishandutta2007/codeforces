#include <iostream>
using namespace std;
const int N = 4002;
const int MOD = 998244353;
typedef long long LL;
int h,w,n;
int r[N], c[N];

LL f[N][N], g[N][N];
LL fac[N];
LL C[N][N];

int main() {
    for (int i = 0; i < N; i ++) C[i][0] = 1;
    for (int i = 1; i < N; i ++) {
        for (int j = 1; j <= i; j ++) 
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }

    fac[0] = 1;
    for (int i = 1; i < N; i ++) fac[i] = fac[i-1] * i % MOD;

    scanf("%d%d%d",&h,&w,&n);
    for(int i=1;i<=n;i++) {
        int r1,c1,r2,c2;
        scanf("%d%d%d%d", &r1,&c1,&r2,&c2);
        r[r1] = r[r2] = 1;
        c[c1] = c[c2] = 1;
    }


    f[0][0] = 1;
    for (int i = 1; i <= h; i ++) {
        for (int j = 0; j <= i / 2; j ++) {
            (f[i][j] += f[i-1][j]) %= MOD;
            if (i >= 2 && r[i] == 0 && r[i-1] == 0 && j >= 1) {
                (f[i][j] += f[i-2][j-1]) %= MOD;
            }
            //printf("f[%d][%d] = %d\n", i, j, f[i][j]);
        }
    }

    g[0][0] = 1;
    for (int i = 1; i <= w; i ++) {
        for (int j = 0; j <= i / 2; j ++) {
            (g[i][j] += g[i-1][j]) %= MOD;
            if (i >= 2 && c[i] == 0 && c[i-1] == 0 && j >= 1) {
                (g[i][j] += g[i-2][j-1]) %= MOD;
            }
           // printf("g[%d][%d] = %d\n", i, j, g[i][j]);
        }
    }   

    int A = 0; for (int i = 1; i <= h; i ++) if (r[i] == 0) A ++;
    int B = 0; for (int i = 1; i <= w; i ++) if (c[i] == 0) B ++;
    LL ans = 0;
    for (int i = 0; i <= h / 2; i ++) {
        for (int j = 0; j <= w / 2; j ++) {
            int a = A - 2 * i;
            int b = B - 2 * j;
            if (j > a || i > b) continue;
            ans = ans + f[h][i] * g[w][j] % MOD * C[a][j] % MOD * C[b][i] % MOD * fac[i] % MOD * fac[j] % MOD;
            ans = ans % MOD;
        }
    }
    cout << ans << endl;
}