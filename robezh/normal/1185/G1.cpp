#include <bits/stdc++.h>
using namespace std;

const int N = 15, T = 225, mod = (int)1e9 + 7;
#define add(to, x) {to += x; to %= mod;}
int dp[T + 5][(1 << N) + 5][4];

int n, t;
int len[N], g[N];

int main() {
    cin >> n >> t;
    for(int i = 0; i < n; i++) cin >> len[i] >> g[i];

    dp[0][0][0] = 1;
    for(int t_cur = 1; t_cur <= t; t_cur++) {
        for(int mask = 1; mask < (1 << n); mask++) {

            for(int i = 0; i < n; i++) {
                if(!((mask >> i) & 1) || t_cur < len[i]) continue;
                int sum = 0;
                for(int j = 0; j <= 3; j++) add(sum, dp[t_cur - len[i]][mask ^ (1 << i)][j]);
                add(dp[t_cur][mask][g[i]], (sum - dp[t_cur - len[i]][mask ^ (1 << i)][g[i]]) % mod);
            }
        }
    }
    int res = 0;
    for(int mask = 1; mask < (1 << n); mask++) {
        for(int gr = 1; gr <= 3; gr++) {
            add(res, dp[t][mask][gr]);
        }
    }
    cout << (res % mod + mod) % mod << endl;



}