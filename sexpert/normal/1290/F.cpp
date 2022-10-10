#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5, MAXL = 31, MAXC = 4*MAXN + 1;
const int MOD = 998244353;
int dp[MAXL][MAXC][MAXC][MAXC][MAXC][2][2];
/* current prefix, carry (neg/pos) (x/y), x > n, y > n */

int x[5], y[5], sum_nx[32], sum_px[32], sum_ny[32], sum_py[32];

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for(int msk = 0; msk < (1 << n); msk++) {
        for(int i = 0; i < n; i++)
            if(msk & (1 << i)) {
                sum_px[msk] += x[i] * (x[i] > 0);
                sum_nx[msk] -= x[i] * (x[i] < 0);
                sum_py[msk] += y[i] * (y[i] > 0);
                sum_ny[msk] -= y[i] * (y[i] < 0);
            }
    }
    dp[0][0][0][0][0][0][0] = 1;
    for(int pref = 0; (1 << pref) <= m; pref++) {
        int q = (1 << pref);
        for(int cnx = 0; cnx < 4 * n; cnx++) {
            for(int cny = 0; cny < 4 * n; cny++) {
                for(int cpx = 0; cpx < 4 * n; cpx++) {
                    for(int cpy = 0; cpy < 4 * n; cpy++) {
                        for(int gex = 0; gex < 2; gex++) {
                            for(int gey = 0; gey < 2; gey++) {
                                for(int msk = 0; msk < (1 << n); msk++) {
                                    int nnx = cnx + sum_nx[msk];
                                    int npx = cpx + sum_px[msk];
                                    int nny = cny + sum_ny[msk];
                                    int npy = cpy + sum_py[msk];
                                    if(nnx % 2 != npx % 2)
                                        continue;
                                    if(nny % 2 != npy % 2)
                                        continue;
                                    int bx = nnx % 2, by = nny % 2, bm = ((m & q) >> pref), ngx, ngy;
                                    if(bx != bm)
                                        ngx = bx > bm;
                                    else
                                        ngx = gex;
                                    if(by != bm)
                                        ngy = by > bm;
                                    else
                                        ngy = gey;
                                    add(dp[pref + 1][nnx / 2][nny / 2][npx / 2][npy / 2][ngx][ngy], dp[pref][cnx][cny][cpx][cpy][gex][gey]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << (dp[32 - __builtin_clz(m)][0][0][0][0][0][0] + MOD - 1) % MOD << '\n';
}