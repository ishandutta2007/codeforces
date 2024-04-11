#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 200000 + 10;
LL fac[N], invfac[N];

LL mpow(LL a, LL x) {
    if (x == 0) return 1;
    LL t = mpow(a, x >> 1);
    if (x % 2 == 0) return t * t % MOD;
    return t * t % MOD * a % MOD;
}
LL c(int x, int y) {
    return fac[x] * invfac[y] % MOD * invfac[x - y] % MOD;
}
pair<int, int> p[N];

int h, w, n;
LL dp[2002][2];

int main() {
    fac[0] = 1, invfac[0] = 1;
    for (int i = 1; i < N; i ++) {
        fac[i] = fac[i-1] * i % MOD;
        invfac[i] = invfac[i-1] * mpow(i, MOD-2) % MOD;
    }
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }    
    p[n + 1] = make_pair(h, w); ++ n;
    sort(p + 1, p + 1 + n);
    dp[0][0] = 1;
    p[0] = make_pair(1, 1);
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j < 2; j ++) {
            // printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            for (int k = i + 1; k <= n; k ++) {
                if (p[i].second <= p[k].second) {
                    dp[k][j ^ 1] += dp[i][j] * c(p[k].second - p[i].second + p[k].first - p[i].first, p[k].first - p[i].first);
                    dp[k][j ^ 1] %= MOD;
                }
            }
        }
    }
    LL ans = dp[n][1] - dp[n][0];
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;
}