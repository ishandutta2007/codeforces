#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

int n,k;
int a[105], b[105];
int dp[105][200050];

bool in_bound(int i, int j){
    int dif = b[i] - a[i];
    return (j-dif) >= 0 && (j-dif) <= (int)2e5;
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i], b[i] *= k;
    for(int i = 0; i <= n; i++) fill(dp[i], dp[i]+200050, -INF);
    dp[0][100000] = 0;
    int res = -1;
    for(int i = 1; i <= n; i++){
        for(auto j = (int)2e5; j >= 0; j--){
            int dif = b[i]-a[i];
            if(in_bound(i,j) && dp[i-1][j-dif] != -INF)
                dp[i][j] = max(dp[i][j], dp[i-1][j-dif] + a[i]);
            res = max(res, dp[i][100000]);
        }
        for(auto j = (int)2e5; j >= 0; j--) dp[i][j] = max(dp[i][j], dp[i-1][j]);
    }
    cout << res;
}