#include <iostream>
using namespace std;
typedef long long LL;
const int MOD = 1000000007;
LL f[102], g[102], dp_b[102][102][102], vis[102][102][102], dp_f[102][102][102], cnt[102][102][102], all[102][102][102];
int n, x;
char s[102];
LL mpow(LL a, LL x) {
    if (x == 0)
        return 1;
    LL t = mpow(a, x/2);
    if (x % 2 == 0)
        return t * t % MOD;
    return t * t % MOD * a % MOD;
}
LL cac(int l, int r, int k) {
    if (vis[l][r][k] == 1)
        return cnt[l][r][k];

    vis[l][r][k] = 1;

    if (k == 1) {
        if (l == r && s[l] == '1')
            return cnt[l][r][k] = 1; 
        return 0;
    }
    if (k == 0) {
        if (l == r && s[l] == '0')
            return cnt[l][r][k] = 1; 
        return 0;
    }

    ( cnt[l][r][k] += cac(l,r,k-1) * (r==n?mpow(2,g[k-2]):1) ) %= MOD;
    ( cnt[l][r][k] += cac(l,r,k-2) * (l==1?mpow(2,g[k-1]):1) ) %= MOD;
    for (int i = l; i < r; i ++) {
        cac(l, i, k-1), cac(i+1, r, k-2);
        (cnt[l][r][k] += cnt[l][i][k-1]*cnt[i+1][r][k-2]) %= MOD;
    }
    return cnt[l][r][k];
}


int main() {
    scanf("%d %d %s", &n, &x, s+1);
    f[0] = f[1] = 1; g[0] = g[1] = 1;
    for (int i = 2; i <= x; i ++) {
        g[i] = (g[i-1] + g[i-2]) % (MOD - 1);
    }
    cac(1,n,x);
    printf("%lld\n", cnt[1][n][x]);
}