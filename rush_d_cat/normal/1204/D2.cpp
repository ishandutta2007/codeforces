#include <iostream>
#include <cstring>
using namespace std;
const int inf=1e9+7;
const int N=100000+10;
char s[N];
int suf[N][2],pre[N][2],dp[N][2],a[N];
int main() {
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) a[i]=s[i]-'0';

    for(int i=0;i<=n+1;i++){
        suf[i][0]=suf[i][1]=-inf;
        pre[i][0]=pre[i][1]=-inf;
        dp[i][0]=dp[i][1]=-inf;
    }
    suf[n+1][0]=pre[0][0]=0, suf[n+1][1]=pre[0][1]=0;

    suf[n][a[n]]=1;
    for(int i=n-1;i>=1;i--){
        suf[i][a[i]]=1;
        suf[i][0]=max(suf[i+1][0] + (a[i]==0?1:0), suf[i][0]);
        suf[i][0]=max(suf[i+1][1] + (a[i]==0?1:0), suf[i][0]);
        suf[i][1]=max(suf[i+1][1] + (a[i]==1?1:0), suf[i][1]);
        // printf("i=%d, suf(%d,%d)\n", i,suf[i][0],suf[i][1]);
    }
    pre[1][a[1]]=1;
    for(int i=2;i<=n;i++){
        pre[i][a[i]]=1;
        pre[i][0]=max(pre[i-1][0] + (a[i]==0?1:0), pre[i][0]);
        pre[i][0]=max(pre[i-1][1] + (a[i]==0?1:0), pre[i][0]);
        pre[i][1]=max(pre[i-1][1] + (a[i]==1?1:0), pre[i][1]);
    }

    dp[1][a[1]]=1;
    for(int i=1;i<=n;i++){
        int pre0=-inf,pre1=-inf;
        int suf0=-inf,suf1=-inf;
        suf0=max(suf[i+1][0],suf[i+1][1]) + 1;
        //printf("# i=%d, suf0=%d\n", i,suf0);
        if(suf0==max(suf[i][0],suf[i][1])) {
            printf("0");
            dp[i][0]=max(dp[i-1][0]+1, dp[i][0]);
            dp[i][1]=dp[i-1][1];   
        } else {
            printf("1");
            dp[i][0]=dp[i-1][0];
            dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1;
        }
    }
}