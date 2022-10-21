#include <bits/stdc++.h>
using namespace std;

const int N = 505, mod = 998244353;
typedef long long ll;

int n,k;
int dp[N][N];

int main(){
    for(int i = 0; i < N; i++) fill(dp[i], dp[i]+N, 0);

    for(int inter = 1; inter < N; inter++){
        dp[inter][0] = 1;
        for(int j = 1; j <= 500; j++){
            for(int t = max(0, j - inter); t < j; t++){
                dp[inter][j] = (dp[inter][t] + dp[inter][j]) % mod;
            }
        }
    }
    cin >> n >> k;
    if(k == 1) return !printf("0");
    ll res = 0;
//
//    for(int i = 0; i <= n; i++) cout << dp[i][n] << " ";
//    cout << endl;

    for(int i = 1; i <= min(n, k); i++){
        int h = i, c = min(n, (k - 1) / h);
        //cout << h << " " << c << endl;

        res = (res + 1LL * (dp[h][n] - dp[h-1][n]) * dp[c][n] % mod) % mod;
    }
    cout << res * 2 % mod<< endl;
}