#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1005;
const int MOD = 1000000007;

int ans[N + 11][N + 11], C[N + 11][N + 11];
int f[N + 11];

int main() {
    for(int i = 0; i <= N; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
    
    f[0] = 1;
    
    for(int k = 1; k <= N; k++) {
        if (k * (k - 1) / 2 > N)
            continue;
        long long fac = 1;
        for(int i = 1; i <= k; i++) {
            fac *= i;
            fac %= MOD;
        }
        
        for(int i = N; i >= 0; i--) {
            for(int times = 1; times * k + i <= N; times++) {
                (f[i + times * k] += f[i]) %= MOD;
            }
        }
        
        for(int n = 0; n <= N; n++) {
            int tot = k * (k - 1) / 2;
            ans[n][k] = 0;
            int nn = n - tot;
            for(int x = 0; x <= nn; x++) {
                (ans[n][k] += 1LL * f[x] * fac % MOD * C[nn - x + 1][k] % MOD) %= MOD;
            }
        }
    }
    
    int test;
    scanf("%d", &test);
    while(test--) {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("%d\n", ans[n - 1][k]);
    }
    return 0;
}