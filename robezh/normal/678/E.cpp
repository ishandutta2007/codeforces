#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int N = 20;

int n;
ld p[N][N];
ld dp[(1 << N)][N];


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> p[i][j];
    dp[(1 << n) - 1][0] = 1;
    for(int mask = (1 << n) - 2; mask >= 1; mask--) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if((mask >> j) & 1) continue;
                dp[mask][i] = max(dp[mask][i], dp[mask|(1<<j)][j] * p[j][i] + dp[mask|(1<<j)][i] * p[i][j]);
            }
        }
    }
    ld res = 0;
    for(int i = 0; i < n; i++) res = max(res, dp[(1 << i)][i]);
    cout << fixed << setprecision(10) << res << endl;

}