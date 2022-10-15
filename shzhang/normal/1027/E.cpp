#include <cstdio>

using namespace std;

#define MOD 998244353
#define mul(a, b) (((long long)(a) * (long long)(b)) % MOD)

int f[505][505];

int main()
{
    for (int i = 1; i <= 500; i++) f[0][i] = 1;
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            for (int k = 1; k <= j; k++) {
                if (i-k < 0) break;
                f[i][j] += f[i-k][j];
                if (f[i][j] >= MOD) f[i][j] -= MOD;
            }
        }
    }
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 500; i >= 2; i--) {
        f[n][i] -= f[n][i-1];
        f[n][i] %= MOD; f[n][i] += MOD; f[n][i] %= MOD;
        //if (i < 10) printf("%d ", f[n][i]);
    }
    int ans = 0;
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            if (i * j < k) {
                ans += mul(f[n][i], f[n][j]);
                if (ans >= MOD) ans -= MOD;
            }
        }
    }
    printf("%lld", mul(ans, 2));
    return 0;
}