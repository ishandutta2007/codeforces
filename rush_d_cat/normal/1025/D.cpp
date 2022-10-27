#include <iostream>
#include <cstring>
using namespace std;
const int N = 702;
int n,a[N],mp[N][N];
int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}

int dp[N][N][2];

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++){
            if(gcd(a[i],a[j]) > 1)
                mp[i][j] = mp[j][i] = 1;
        }
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<i;j++){
            dp[i][j][0]=dp[i][j][1]=1;
        }
    }
    for(int i=1;i<=n;i++) mp[0][i]=mp[i][0]=mp[i][n+1]=mp[n+1][i]=1;
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            for(int k=i;k<=j;k++){

                if (mp[k][j+1] && dp[i][k-1][0] && dp[k+1][j][1]) {
                    dp[i][j][0] = 1;
                }
                if (mp[k][i-1] && dp[i][k-1][0] && dp[k+1][j][1]) {
                    dp[i][j][1] = 1;
                }
            }
            //printf("[%d,%d] %d %d\n", i,j, dp[i][j][0], dp[i][j][1]);
        }
    }
    printf("%s\n", dp[1][n][1] ? "Yes" : "No");
}