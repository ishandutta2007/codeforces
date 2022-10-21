#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e3 + 50, mod = 998244353;
typedef long long ll;

int n;
int num[N];
ll dp[N];
int C[N][N];

int main(){
    for(int i = 0; i < N; i++) C[i][0] = 1;
    for(int i = 1; i < N; i++)
        for(int j = 1; j < N; j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];

    dp[n] = 1;
    for(int i = n-1; i >= 0; i--){
        if(num[i] <= 0) continue;
        for(int j = i + num[i] + 1; j <= n; j++){
            if(dp[j] != 0){
                dp[i] += dp[j] * C[j - 1 - i][num[i]] % mod;
            }
            dp[i] %= mod;
        }
    }
    ll res = 0;
    for(int i = 0; i < n; i++) res += dp[i], res %= mod;
    cout << res;

}