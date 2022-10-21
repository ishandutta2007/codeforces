#include <bits/stdc++.h>
using namespace std;

#define MAXN 100050

int n;
int num[MAXN], dp[2][MAXN];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];

    if(n == 1) return !printf("1");
    if(n == 2) return !printf("2");

    dp[0][0] = 1, dp[0][1] = (num[1] > num[0] ? 2 : 1);
    dp[1][0] = 0, dp[1][1] = 2;
    int res = (n == 1 ? 1 : 2);
    for(int i = 2; i < n; i++){
        dp[0][i] = 1;
        dp[1][i] = 2;
        if(num[i] > num[i-1]) dp[0][i] = max(dp[0][i], dp[0][i-1] + 1),
                              dp[1][i] = max(dp[1][i], dp[1][i-1] + 1);
        if(num[i] > num[i-2] + 1) dp[1][i] = max(dp[1][i], dp[0][i-2]+2);
        res = max(res, max(min(dp[0][i] + 1, n), dp[1][i]));
    }
//    for(int i = 0; i < n; i++){cout << dp[0][i] << " ";}
//    cout << endl;
//    for(int i = 0; i < n; i++){cout << dp[1][i] << " ";}
    cout << res;
}