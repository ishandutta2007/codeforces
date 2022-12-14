#include<cstdio>
using namespace std;

int dp[3000][2][4][2]={0};
int a[3000],b[3000],c[3000];
int max(int x,int y){
    return(x>y)?x:y;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
    if(n==1){
        printf("%d\n",a[0]);
        return 0;
    }
    if(n==2){
        printf("%d\n",max(a[0]+b[1],a[1]+b[0]));
        return 0;
    }
    dp[0][0][0][0]=b[0]+a[1]+b[2];
    dp[0][0][0][1]=b[0]+a[1]+c[2];
    dp[0][0][1][0]=b[0]+b[1]+a[2];
    dp[0][0][1][1]=b[0]+b[1]+b[2];
    dp[0][0][2][0]=a[0]+b[1]+b[2];
    dp[0][0][2][1]=a[0]+b[1]+c[2];
    dp[0][0][3][0]=a[0]+c[1]+a[2];
    dp[0][0][3][1]=a[0]+c[1]+b[2];
    dp[0][1][0][0]=-(1<<30);
    dp[0][1][0][1]=-(1<<30);
    dp[0][1][1][0]=-(1<<30);
    dp[0][1][1][1]=-(1<<30);
    dp[0][1][2][0]=-(1<<30);
    dp[0][1][2][1]=-(1<<30);
    dp[0][1][3][0]=-(1<<30);
    dp[0][1][3][1]=-(1<<30);
    for(int i=1;i<n-2;i++){
        dp[i][0][0][0]=max(dp[i-1][0][1][0],dp[i-1][1][1][0])+b[i+2];
        dp[i][0][0][1]=max(dp[i-1][0][1][0],dp[i-1][1][1][0])+c[i+2];
        dp[i][0][1][0]=max(dp[i-1][0][1][1],dp[i-1][1][1][1])+a[i+2];
        dp[i][0][1][1]=max(dp[i-1][0][1][1],dp[i-1][1][1][1])+b[i+2];
        dp[i][0][2][0]=max(dp[i-1][0][0][0],dp[i-1][1][0][0])+b[i+2];
        dp[i][0][2][1]=max(dp[i-1][0][0][0],dp[i-1][1][0][0])+c[i+2];
        dp[i][0][3][0]=max(dp[i-1][0][0][1],dp[i-1][1][0][1])+a[i+2];
        dp[i][0][3][1]=max(dp[i-1][0][0][1],dp[i-1][1][0][1])+b[i+2];
        dp[i][1][0][0]=max(dp[i-1][0][3][0],dp[i-1][1][3][0])+b[i+2];
        dp[i][1][0][1]=max(dp[i-1][0][3][0],dp[i-1][1][3][0])+c[i+2];
        dp[i][1][1][0]=max(dp[i-1][0][3][1],dp[i-1][1][3][1])+a[i+2];
        dp[i][1][1][1]=max(dp[i-1][0][3][1],dp[i-1][1][3][1])+b[i+2];
        dp[i][1][2][0]=max(dp[i-1][0][2][0],dp[i-1][1][2][0])+b[i+2];
        dp[i][1][2][1]=max(dp[i-1][0][2][0],dp[i-1][1][2][0])+c[i+2];
        dp[i][1][3][0]=max(dp[i-1][0][2][1],dp[i-1][1][2][1])+a[i+2];
        dp[i][1][3][1]=max(dp[i-1][0][2][1],dp[i-1][1][2][1])+b[i+2];
    }
    int ans=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<4;j++)
            if(dp[n-3][i][j][0]>ans)ans=dp[n-3][i][j][0];
    printf("%d\n",ans);
    return 0;
}