#include<bits/stdc++.h>
using namespace std;

#define N 5010
#define K 2555

int a[N], dp[N][K], ep[N][K];

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int k = n+1>>1;
    for(int i = 0; i <= n; i ++) for(int j = 0; j <= k; j ++) dp[i][j] = ep[i][j] = INF;
    ep[0][0] = 0;
    dp[1][1] = 0;
    ep[1][0] = 0;
    for(int i = 2; i <= n; i ++) {
        for(int j = 0; j <= k; j ++) {
            if(a[i-1] >= a[i]) {
                int dn = min(a[i], a[i-2]) - 1;
                if(j) dp[i][j] = min(dp[i][j], dp[i-2][j-1]+a[i-1]-dn);
                dn = a[i]-1;
                if(j) dp[i][j] = min(dp[i][j], ep[i-2][j-1]+a[i-1]-dn);
            }
            else {
                if(j) dp[i][j] = min(dp[i][j], ep[i-1][j-1]);
            }
            ep[i][j] = min(ep[i][j], ep[i-1][j]);
            if(a[i-1] > a[i]) ep[i][j] = min(ep[i][j], dp[i-1][j]);
            else ep[i][j] = min(ep[i][j], dp[i-1][j] + a[i]-a[i-1]+1);
        }
    }
    for(int i = 1; i <= k; i ++) cout << min(dp[n][i], ep[n][i]) << ' ';
    cout << endl;
}