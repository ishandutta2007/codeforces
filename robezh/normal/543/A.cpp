#include <bits/stdc++.h>
using namespace std;

int n,m,b,mod;
int num[505], dp[505][505];

int main() {

    for(int i = 0; i < 505; i++) fill(dp[i], dp[i]+505, 0);
    dp[0][0] = 1;

    cin >> n >> m >> b >> mod;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = num[i]; k <= b; k++){
                dp[j][k] = (dp[j-1][k-num[i]] + dp[j][k]) % mod;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i <= b; i++){
        sum = (sum + dp[m][i]) % mod;
    }
    cout << sum;


}