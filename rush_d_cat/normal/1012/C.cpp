#include <iostream>
using namespace std;
const int N = 5002;
int n, a[N], dp[N][N], f[N][N], ans[N];
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) dp[i][j]=f[i][j]=1e9;
    for(int i=0;i<N;i++) ans[i]=1e9;
    dp[0][0]=f[0][0]=0;
    for(int i=1;i<=n;i++) {
        dp[i][0]=0;
        for(int j=1;j<=(i+1)/2;j++) {
            if(j==1) {
                dp[i][j] = max(a[i+1]-(a[i]-1), 0) + max(a[i+-1]-(a[i]-1), 0);
            } else {
                dp[i][j] = min(((i<2)?0:dp[i-2][j-1])+max(a[i+1]-(a[i]-1), 0)+max(min(a[i-1],a[i-2]-1)-(a[i]-1), 0), dp[i][j]);
                dp[i][j] = min(((i<3)?0:f[i-3][j-1]) +max(a[i+1]-(a[i]-1), 0)+max(a[i-1]-(a[i]-1), 0), dp[i][j]);
            }
            f[i][j] = min(f[i-1][j], dp[i][j]);
            ans[j] = min(ans[j], dp[i][j]);
            //printf("dp[%d][%d]=%d\n", i,j,dp[i][j]);
        }
    }                            
    for(int i=1;i<=(n+1)/2;i++) printf("%d ", ans[i]);
}