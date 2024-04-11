#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 555;
const int MOD = 1000000007;
long long f[N][N];
int n, k;
long long power[N * N];
int main() {
    power[0] = 1;
    scanf("%d %d", &n, &k);
    if (k == 0) {
        printf("1\n");
        return 0;
    }
    for(int i = 1; i <= n * n; i++) {
        power[i] = 2 * power[i - 1] % MOD;
    }
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            for(int p = i + 1; p <= n; p++) {
                int cnt = (p - i - 1) * i + i;
                (f[p][j + 1] += f[i][j] * power[cnt] % MOD * ((power[p - i] - 1 + MOD) % MOD) % MOD) %= MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        (ans += f[i][k] * power[(n - i) * i] % MOD) %= MOD;
    }
    printf("%d\n", ans);
    return 0;
}