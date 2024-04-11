#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500, mod = 998244353;

// #define DEBUG

int n;
int num[N];
ll dp[2][3][205];
ll psum[3][205];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);

#ifdef DEBUG
    n = 100000;
    for(int i = 1; i <= n; i++) num[i] = -1;
#endif


    dp[0][2][1] = 1;
    for(int i = 1; i <= n; i++){
        int t = i % 2, ti = 1 - t;
        int lb = (num[i] == -1 ? 1 : num[i]), rb = (num[i] == -1 ? 200 : num[i]);
        for(int j = 0; j < 3; j++){
            psum[j][0] = 0;
            for(int k = 1; k <= 200; k++){
                psum[j][k] = (dp[ti][j][k] + psum[j][k-1]) % mod;
            }
        }

        for(int j = 0; j < 3; j++){
            for(int k = 1; k <= 200; k++){
                dp[t][j][k] = 0;
            }
        }

        for(int k = lb; k <= rb; k++){
            dp[t][0][k] = (psum[0][200] - psum[0][k] + psum[1][200] - psum[1][k]) % mod;
            dp[t][1][k] = (dp[ti][0][k] + dp[ti][1][k] + dp[ti][2][k]) % mod;
            dp[t][2][k] = (psum[0][k-1] + psum[1][k-1] + psum[2][k-1]) % mod;
        }
//        if(i == 3){
//            cout << dp[t][0][3] << " " << dp[t][1][3] << " " << dp[t][2][3] << endl;
//        }
    }
    ll res = 0;
    int lb = (num[n] == -1 ? 1 : num[n]), rb =  (num[n] == -1 ? 200 : num[n]);
    for(int k = lb; k <= rb; k++){
        res = (res + dp[n%2][0][k] + dp[n%2][1][k]) % mod;
    }
    res = (res + mod) % mod;
    cout << res << endl;
}