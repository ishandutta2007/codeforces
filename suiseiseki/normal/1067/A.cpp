#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
 
#define ll long long
#define ull unsigned long long
#define BUG cout<<"*************************\n"
using namespace std;
 
const ll mod = 998244353;
const int maxn = 4e5 + 10;
const int maxm = 1e6 + 10000;
const double eps = 1e-8;
 
int n, a[maxn];
ll up_sum[maxn][3], down_sum[maxn][3];
ll f[2][211][3];
 
int main() {
    /*ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    if (a[1] == -1) {
        for (int i = 1; i <= 200; ++i) {
            f[1][i][2] = 1;
        }
    } else {
        f[1][a[1]][2] = 1;
    }
    // 1 a[i]<a[i-1]
    // 2 a[i]>a[i-1]
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= 200; ++j)
            f[i & 1][j][0] = f[i & 1][j][1] = f[i & 1][j][2] = 0;
        if (a[i] == -1) {
            if (a[i - 1] == -1) {
                for (int j = 1; j <= 200; ++j) {
                    (up_sum[j][0] = up_sum[j - 1][0] + f[1 - (i & 1)][j][0]) % mod;
                    (up_sum[j][1] = up_sum[j - 1][1] + f[1 - (i & 1)][j][1]) % mod;
                    (up_sum[j][2] = up_sum[j - 1][2] + f[1 - (i & 1)][j][2]) % mod;
                }
                for (int j = 200; j >= 1; --j) {
                    (down_sum[j][0] = down_sum[j + 1][0] + f[1 - (i & 1)][j][0]) % mod;
                    (down_sum[j][1] = down_sum[j + 1][1] + f[1 - (i & 1)][j][1]) % mod;
                    (down_sum[j][2] = down_sum[j + 1][2] + f[1 - (i & 1)][j][2]) % mod;
                }
                for (int j = 1; j <= 200; ++j) {
                    f[i & 1][j][0] = (f[1 - (i & 1)][j][0] + f[1 - (i & 1)][j][1] + f[1 - (i & 1)][j][2]) % mod;
                    f[i & 1][j][1] = (down_sum[j + 1][0] + down_sum[j + 1][1]) % mod;
                    f[i & 1][j][2] = (up_sum[j - 1][0] + up_sum[j - 1][1] + up_sum[j - 1][2]) % mod;
                }
            } else {
                for (int j = 1; j < a[i - 1]; ++j) {
                    f[i & 1][j][1] = (f[1 - (i & 1)][a[i - 1]][0] + f[1 - (i & 1)][a[i - 1]][1]) % mod;
                }
                f[i & 1][a[i - 1]][0] =
                        (f[1 - (i & 1)][a[i - 1]][0] + f[1 - (i & 1)][a[i - 1]][1] + f[1 - (i & 1)][a[i - 1]][2]) % mod;
                for (int j = a[i - 1] + 1; j <= 200; ++j) {
                    f[i & 1][j][2] = (f[1 - (i & 1)][a[i - 1]][0] + f[1 - (i & 1)][a[i - 1]][1] +
                                      f[1 - (i & 1)][a[i - 1]][2]) % mod;
                }
            }
        } else {
            if (a[i - 1] == -1) {
                for (int j = 1; j < a[i]; ++j) {
                    f[i & 1][a[i]][2] += f[1 - (i & 1)][j][0] + f[1 - (i & 1)][j][1] + f[1 - (i & 1)][j][2];
                    f[i & 1][a[i]][2] %= mod;
                }
                f[i & 1][a[i]][0] = (f[1 - (i & 1)][a[i]][0] + f[1 - (i & 1)][a[i]][1] + f[1 - (i & 1)][a[i]][2]) % mod;
                for (int j = a[i] + 1; j <= 200; ++j) {
                    f[i & 1][a[i]][1] += f[1 - (i & 1)][j][0] + f[1 - (i & 1)][j][1];
                    f[i & 1][a[i]][1] %= mod;
                }
            } else {
                if (a[i] > a[i - 1]) {
                    f[i & 1][a[i]][2] =
                            (f[1 - (i & 1)][a[i - 1]][0] + f[1 - (i & 1)][a[i - 1]][1] + f[1 - (i & 1)][a[i - 1]][2]) %
                            mod;
                } else if (a[i] == a[i - 1]) {
                    f[i & 1][a[i]][0] =
                            (f[1 - (i & 1)][a[i - 1]][0] + f[1 - (i & 1)][a[i - 1]][1] + f[1 - (i & 1)][a[i - 1]][2]) %
                            mod;
                } else {
                    f[i & 1][a[i]][1] = (f[1 - (i & 1)][a[i - 1]][0] + f[1 - (i & 1)][a[i - 1]][1]) % mod;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 200; ++i) {
        ans += f[n & 1][i][0] + f[n & 1][i][1];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}