#include <iostream>
using namespace std;
const int N=5002;
int c[N],n,a[N],m,dp[N][N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);

    for(int i=1;i<=n;i++){
        if(c[i]!=c[i-1])
            a[++m]=c[i];
    }
    n=m;
    for(int i=1;i<=n;i++)
        c[i]=a[n+1-i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==c[j])
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    printf("%d\n", n-(dp[n][n]+1)/2);
}