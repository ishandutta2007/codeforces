#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int MOD = 1e9 + 7;
int dpsum[MAXN][MAXN], dp[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    char t;
    dp[1][0] = dpsum[1][0] = 1;
    for(int m = 2; m <= n; m++) {
        cin >> t;
        for(int k = m - 1; k >= 0; k--) {
            if(t == 's')
                dp[m][k] = dpsum[m - 1][k];
            else
                dp[m][k] = (k > 0 ? dp[m - 1][k - 1] : 0);
            dpsum[m][k] = (dpsum[m][k + 1] + dp[m][k]) % MOD;
        }
    }
    cin >> t;
    cout << dpsum[n][0] << endl;
}