#include <bits/stdc++.h>
using namespace std;

const int N = 505, mod = (int)1e9 + 7;

int n, k;
int dp[2][N][N];
int pw[N];

void add(int &to, int x) {
    to += x;
    if(to >= mod) to -= mod;
}

int main() {
    pw[0] = 1;
    for(int i = 1; i < N; i++) pw[i] = pw[i-1] * 2 % mod;

    cin >> n >> k;

    int nw = 1, la = 0;
    dp[nw][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        swap(nw, la);
        memset(dp[nw], 0, sizeof(dp[nw]));
        for(int j = 0; j < i; j++) {
            for(int t = 0; t <= k; t++) {
                if(dp[la][j][t] == 0) continue;
                add(dp[nw][i][t+1], (int)((1LL * dp[la][j][t] * (pw[i - j] - 1) % mod * pw[j]) % mod));
                add(dp[nw][j][t], (int)(1LL * dp[la][j][t] * pw[j] % mod));
            }
        }
    }
    int res = 0;
    for(int i = 0; i <= n; i++) {
        add(res, dp[nw][i][k]);
    }
    cout << res << endl;
}