#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;

LL mpow(LL a, LL x){ 
    if (x == 0) return 1;
    LL t = mpow(a, x>>1);
    if (x % 2 == 0) return t * t % MOD;
    return t * t % MOD * a % MOD; 
}


const int N = 252;
int n, k;

LL c[N][N];
int main() {
    for (int i = 0; i < N; i ++) c[i][0] = 1;
    for (int i = 1; i < N; i ++) {
        for (int j = 1; j <= i; j ++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
        }
    }
    int n, k; cin >> n >> k;

    LL ans = 0;
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= n; j ++) {
            int cnt = i * n + j * n - i * j;
            LL ways = mpow(k - 1, cnt) * mpow(k, n * n - cnt) % MOD;
            ways = ways * c[n][i] % MOD * c[n][j] % MOD;
            if ( (i+j) % 2 == 0 )
                ans = ans + ways;
            else
                ans = ans - ways;

            ans = (ans % MOD + MOD) % MOD;
        }
    }

    cout << ans << endl;
}