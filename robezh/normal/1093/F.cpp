#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, M = 105, mod = 998244353;

int n,k,len;
int num[N], dp[N][M];
int cnt[N][M];
int sdp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> len;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        if(num[i] == -1) num[i] = 0;
        cnt[i][num[i]] = 1;
        for(int j = 0; j <= k; j++) cnt[i][j] += cnt[i-1][j];
    }

    dp[0][0] = 1; sdp[0] = 1;
    for(int i = 1; i <= n; i++) {
        int mn = 1, mx = k;
        if(num[i] != 0) mn = mx = num[i];

        for(int j = mn; j <= mx; j++) {
            dp[i][j] = sdp[i-1];
            if(i - len >= 0 && (cnt[i][j] - cnt[i-len][j] + cnt[i][0] - cnt[i-len][0]) == len){
                dp[i][j] -= (sdp[i-len] - dp[i-len][j]) % mod;
            }
            dp[i][j] %= mod;
        }
        for(int j = 1; j <= k; j++){
            sdp[i] += dp[i][j];
            sdp[i] %= mod;
        }
    }
    cout << (sdp[n] % mod + mod) % mod << endl;
}