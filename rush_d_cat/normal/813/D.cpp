#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int dp[5010][5010];
int n, a[5010];
int maxmod[8], maxnum[100000+2];
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) 
        cin >> a[i];
    
    for(int y=0;y<=n;y++) {
        for(int i=0;i<7;i++) {
            maxmod[i] = 0;
        }
        for(int i=1;i<=n;i++) {
            maxnum[a[i]] = 0;
        }

        for(int x=1;x<y;x++) {
            maxnum[a[x]] = max(maxnum[a[x]], dp[x][y]);
            maxmod[a[x]%7] = max(dp[x][y], maxmod[a[x]%7]);
        }

        for(int x=y+1;x<=n;x++) {
            dp[y][x] = dp[x][y] = 1 + max(max(maxmod[a[x]%7], dp[0][y]), max(maxnum[a[x]-1], maxnum[a[x]+1]));
            maxmod[a[x]%7]  = max(dp[x][y], maxmod[a[x]%7]);
            maxnum[a[x]] = max(dp[x][y], maxnum[a[x]]);
        }

    }
    
    int ans = 0;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) 
            ans = max(ans, dp[i][j]);
    cout << ans << endl;
}