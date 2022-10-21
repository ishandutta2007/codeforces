#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 51, T = 2505, mod = (int)1e9 + 7;
#define add(to, x) {to += x; to %= mod;}


int n, t;
int len[N], g[N];
int sig[N][T], comb[N][N][T];
int ways[N][N][N], coe[N][N][N][4];
ll fac[N];

int main() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = fac[i-1] * i % mod;
    cin >> n >> t;
    for(int i = 0; i < n; i++) cin >> len[i] >> g[i];

    sig[0][0] = 1;
    comb[0][0][0] = 1;
    for(int i = 0; i < n; i++) {
        if(g[i] == 1) {
            for(int t_cur = t; t_cur >= len[i]; t_cur--) {
                for(int j = n; j >= 1; j--) add(sig[j][t_cur], sig[j-1][t_cur-len[i]]);
            }
        }
        else {
            for(int t_cur = t; t_cur >= len[i]; t_cur--) {
                for(int j = n; j >= (g[i] == 2); j--) {
                    for(int k = n; k >= (g[i] == 3); k--) {
                        add(comb[j][k][t_cur], comb[j - (g[i] == 2)][k - (g[i] == 3)][t_cur - len[i]]);
                    }
                }
            }
        }
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= n; k++) {
                for(int t_cur = 0; t_cur <= t; t_cur++) {
                    add(ways[i][j][k], (int)(1LL * sig[i][t_cur] * comb[j][k][t - t_cur] % mod));
                }
//                cout << i << ", " << j << ", " << k << ": " << ways[i][j][k] << endl;
            }

    coe[0][0][0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= n; k++) {
                for(int gc = 1; gc <= 3; gc++) {
                    if(gc == 1 && i >= 1) for(int gr = 0; gr <= 3; gr++)
                        add(coe[i][j][k][gc], (gc != gr) * coe[i-1][j][k][gr]);
                    if(gc == 2 && j >= 1) for(int gr = 0; gr <= 3; gr++)
                        add(coe[i][j][k][gc], (gc != gr) * coe[i][j-1][k][gr]);
                    if(gc == 3 && k >= 1) for(int gr = 0; gr <= 3; gr++)
                        add(coe[i][j][k][gc], (gc != gr) * coe[i][j][k-1][gr]);
                }
            }
        }
    }
    ll res = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= n; k++) {
//                cout << i << ' ' << j << " " << k << ": " << (coe[i][j][k][1] + coe[i][j][k][2] + coe[i][j][k][3]) << endl;
                res += (1LL * coe[i][j][k][1] + coe[i][j][k][2] + coe[i][j][k][3]) % mod
                        * ways[i][j][k] % mod * fac[i] % mod * fac[j] % mod * fac[k] % mod;
                res %= mod;
            }
        }
    }
    cout << res << endl;
}