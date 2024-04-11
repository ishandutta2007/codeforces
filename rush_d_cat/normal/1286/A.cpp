#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N=200+10;
int n,a[N],dp[N][N][2];
int main() {
    scanf("%d",&n);
    int x=(n+1)/2,y=n/2;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]){
            if(a[i]%2==1)--x;
            else --y;
        }
    }
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j][0]=dp[i][j][1]=1e9;
    if(a[1]) {
        dp[1][0][a[1]%2]=0;
    } else {
        if(x) dp[1][1][1]=0;
        if(y) dp[1][0][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(a[i+1]){
                for(int k=0;k<2;k++){
                    dp[i+1][j][a[i+1]%2] = min(dp[i+1][j][a[i+1]%2], dp[i][j][k] + (k==(a[i+1]%2)?0:1));
                }
            } else {
                for(int k=0;k<2;k++){
                    dp[i+1][j+1][1] = min(dp[i+1][j+1][1], dp[i][j][k] + ((k==1)?0:1));
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k] + ((k==0)?0:1));
                }
            }
        }
    }
    printf("%d\n", min(dp[n][x][0],dp[n][x][1]));
    /*
    int xx,yy,z; while(1){
        cin>>xx>>yy>>z;cout<<dp[xx][yy][z]<<endl;
    }
    */
}