#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int NMAX = 1010;

ll ct[NMAX][NMAX]; // level, position (WLOG going rightward)

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);
        memset(ct, 0, sizeof ct);
        for (int i = 0; i <= n; ++i) ct[1][i] = 1;
        for (int lv = 2; lv <= k; ++lv) {
            ct[lv][n] = 1;
            for (int pos = n-1; pos >= 0; --pos) {
                ct[lv][pos] = (ct[lv][pos+1] + ct[lv-1][n-pos]) % MOD; 
            }
        }
        printf("%lld\n", ct[k][0]);
    }
}