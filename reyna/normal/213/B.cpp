//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 120;
const int Mod = 1e9 + 7;
int need[10];
int dp[Maxn][11];
long long C[Maxn][Maxn];
long long rec(int n,int k){
//  cerr << " " << n << " " << k << endl;
    if(dp[n][k+1] != -1)
        return dp[n][k+1];
    long long ret = 0;
    for(int i = need[k]; i <= n;i++){
//      cerr << i << " " << k << " " << n << " " << rec(n-i,k-1) << " " << C[i][n] << endl;
        ret += rec(n - i, k - 1) * C[n][i];
        ret %= Mod;
    }
//  cerr << n << " " << k << " :) " << ret << endl;
    return dp[n][k+1] = ret % Mod;
}
int main(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < 10;i++){
        cin >> need[i];
        sum += need[i];
    }
    for(int i = 0; i < Maxn;i++)
        for(int j = 0; j < 11;j++)
            dp[i][j] = -1;
    for(int i = 0; i < Maxn;i++){
        for(int j = 0; j <= i;j++){
            if(i == j || !j)
                C[i][j] = 1;
            else
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % Mod;
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n;i++)
        dp[i][0] = 0;
    long long ans = rec(n,9);
    ans %= Mod;
    for(int i = 0; i < n;i++){
        if(need[0])
            ans += rec(i,9);
        ans %= Mod;
    }
    if(need[0]){
        for(int i = 0; i < Maxn;i++)
            for(int j = 0; j < 11;j++)
                dp[i][j] = -1;
        dp[0][0] = 1;
        for(int i = 1; i <= n;i++)
            dp[i][0] = 0;
        --need[0];
        for(int i = 0; i < n;i++){
            ans -= rec(i,9);
            ans %= Mod;
            ans += Mod;
            ans %= Mod;
        }
    }
    if(!sum)
        ans--;
    cout << ans % Mod << endl;
    return 0;
}