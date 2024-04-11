#include <bits/stdc++.h>
using namespace std;

const int HF = 10025, mod = (int)1e9 + 7;

int n, a;
int dp[2][2 * HF];
int ans = 0;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        dp[(i+1)%2][HF] += 1;
        for(int j = 0; j < 2*HF; j++) dp[i%2][j] = 0;
        for(int j = -10000; j <= 10000; j++){
            if(j + a <= 10000) dp[i%2][j+a+HF] = (dp[i%2][j+a+HF] + dp[(i+1)%2][j+HF]) % mod;
            if(j - a >= -10000) dp[i%2][j-a+HF] = (dp[i%2][j-a+HF] + dp[(i+1)%2][j+HF]) % mod;
        }
        ans = (ans + dp[i%2][HF]) % mod;
    }
    cout << ans << endl;
}