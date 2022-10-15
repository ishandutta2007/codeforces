#include <cstdio>
//
using namespace std;

#define ll long long
#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int n, c;
int a[3005];
int f[3005][3005];
int pwr2m1[3005];
int pwr2m1_inv[3005];
int pwr2m1_rep[3005];
int left[3005];
//int nxt[3005][12];
int tmp[3005];
int prod[3005][3005];
int f2[2][3005][1024];
//vector<int> pos[3005];
//int total_freq[3005];

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

int main()
{
    for (int i = 1; i <= 3000; i++) {
        pwr2m1[i] = (mul(pwr2m1[i-1], 2) + 1) % MOD;
        pwr2m1_inv[i] = fpow(pwr2m1[i], MOD - 2);
        pwr2m1_rep[i] = mul(pwr2m1[i], pwr2m1_inv[i - 1]);
        //if (i <= 20) printf("%d %d\n", pwr2m1[i], pwr2m1_inv[i]);
    }
    pwr2m1_rep[1] = 1;
    scanf("%d%d", &n, &c);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        f[0][i] = (pwr2m1[i] + 1) % MOD;
        //total_freq[a[i]]++;
    }
    if (c > 10) {
        int lptr = 1; int remain = c;
        for (int i = 1; i <= n; i++) {
            if (!tmp[a[i]]) remain--;
            tmp[a[i]]++;
            if (!remain) {
                while (tmp[a[lptr]] >= 2) {
                    tmp[a[lptr]]--; lptr++;
                }
                left[i] = lptr;
            }
        }

        for (int r = 1; r <= n; r++) {
            int curprod = 1;
            for (int i = 1; i <= c; i++) tmp[i] = 0;
            for (int l = r; l >= 1; l--) {
                tmp[a[l]]++;
                curprod = mul(curprod, pwr2m1_rep[tmp[a[l]]]);
                prod[l][r] = mul(curprod, pwr2m1_inv[tmp[a[l]]]);
            }
        }
        for (int d = 1; d <= n / c; d++) {
            //for (int i = 1; i <= c; i++) pos[i].clear();
            for (int i = d * c; i <= n; i++) {
                for (int j = left[i]; j >= (d - 1) * c; j--) {
                    f[d][i] += mul(f[d-1][j-1], prod[j][i]);
                    if (f[d][i] >= MOD) f[d][i] -= MOD;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            printf("%d ", (f[i][n] - f[i+1][n] - (i == 0 ? 1 : 0) + MOD) % MOD);
        }
    } else {
        for (int i = 1; i <= n; i++) a[i] = (1 << (a[i] - 1));
        f2[0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            int old = (i & 1);
            int nw = (old ^ 1);
            for (int j = 0; j <= i / c; j++) {
                for (int k = 0; k < (1 << c); k++) {
                    f2[nw][j][k] += f2[old][j][k];
                    if (f2[nw][j][k] >= MOD) f2[nw][j][k] -= MOD;
                    int new_bits = k | a[i+1];
                    if (new_bits == ((1 << c) - 1)) {
                        f2[nw][j+1][0] += f2[old][j][k];
                        if (f2[nw][j+1][0] >= MOD) f2[nw][j+1][0] -= MOD;
                    } else {
                        f2[nw][j][new_bits] += f2[old][j][k];
                        if (f2[nw][j][new_bits] >= MOD) f2[nw][j][new_bits] -= MOD;
                    }
                    f2[old][j][k] = 0;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            int ans = 0;
            for (int j = 0; j < (1 << c); j++) {
                ans += f2[n&1][i][j]; if (ans >= MOD) ans -= MOD;
            }
            if (i == 0) {
                ans--; if (ans < 0) ans += MOD;
            }
            printf("%d ", ans);
        }
    }
    return 0;
}