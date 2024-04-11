#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

int n = 0;
int dp[200050];
int r,g;

int main(){
    cin >> r >> g;
    while((n+1) * (n+2) / 2 <= r + g) n++;
    int m = min(r,g);
    fill(dp, dp+200050, 0); dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= i; j--){
            dp[j] = (dp[j] + dp[j-i]) % mod;
        }
    }
    //cout << n << endl;
    int res = 0;
    int s = max(0, n * (n+1) / 2 - max(r,g));
    for(int i = s; i <= m; i++){
        res = (res + dp[i]) % mod;
    }
    cout << res << endl;
}