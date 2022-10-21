#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1002;
const int mod = (int)1e9 + 7;

ll fac[N];
int dp[50][N][N];
//int psum[50][N][N];



int main(){
    dp[0][0][0] = 1;
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++) dp[0][i][j] = 1;
    }
    for(int k = 1; k < 50; k++){
        for(int i = 1; i < N; i++){
            for(int j = 1; j < N; j++){
                dp[k][i][j] = dp[k][i-1][j];
                if(j >= 1){
                    dp[k][i][j] += (dp[k][i][j-1] - dp[k][i-1][j-1]) % mod;
                    dp[k][i][j] %= mod;
                    if(i - j >= 0){
                        dp[k][i][j] += dp[k-1][i-j][j-1];
                        dp[k][i][j] %= mod;
                    }
                }

            }
        }
    }
    fac[0] = 1;
//    int i, j, k;
//    while(cin >> i >> j >> k){
//        cout << dp[i][j][k] << endl;
//    }
    for(int i = 1; i <= 1000; i++) fac[i] = fac[i-1] * i % mod;
    int T;
    scanf("%d", &T);
    while(T--){
        int n, k;
        scanf("%d%d", &n, &k);
        if(k < 50){
            ll res = 1LL * dp[k][n][n+1] * fac[k];
            printf("%I64d\n", (res % mod + mod) % mod);
        }
        else printf("0\n");
    }
}