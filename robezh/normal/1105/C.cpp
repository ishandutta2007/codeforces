#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7, N = (int)2e5 + 50;

int n, l, r;
int cnt[3];
ll dp[3][N];

int main() {
    cin >> n >> l >> r;
    for(int i = 0; i < 3; i++) {
        cnt[i] = (r - i + 3) / 3 - (l - 1 - i + 3) / 3;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                dp[(j + k) % 3][i] += dp[j][i-1] * cnt[k] % mod;
                dp[(j + k) % 3][i] %= mod;
            }
        }
    }
    cout << dp[0][n] << endl;
}