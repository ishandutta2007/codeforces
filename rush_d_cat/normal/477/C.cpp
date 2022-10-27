#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 2000+10;
char s[N],t[N]; int n,m;
int dp[N][N],pre[N],ans[N];
void getpos(int pos){
    int last=m;
    for(int i=pos;i>=1;i--){
        if(t[last]==s[i]) last--;
        if(last==0) {
            //printf("%d %d\n", pos,i);
            pre[pos]=i;return;
        }
    }
    pre[pos]=0;
}

int main() {
    scanf("%s%s",s+1,t+1); 
    n=strlen(s+1), m=strlen(t+1);
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=1e9; dp[0][0]=0;
    for(int i=1;i<=n;i++) getpos(i);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n/m;j++){
            dp[i][j]=dp[i-1][j];
            if(pre[i]!=0){
                dp[i][j]=min(dp[i][j],dp[pre[i]-1][j-1]+(i-pre[i]+1)-m);
            }
            //printf("dp[%d][%d]=%d\n", i,j,dp[i][j]);
        }
    }
    for(int i=0;i<=n/m;i++){
        //printf("ans[%d]=%d\n", i,dp[n][i]);
        if(dp[n][i]>1e9-1)continue;
        ans[dp[n][i]] = max(ans[dp[n][i]],i);
    }
    for(int i=1;i<=n;i++) ans[i]=max(ans[i],ans[i-1]);
    int mx = ans[n],cnt=0;
    for(int i=n;i>=1;i--) {
        if((n-i)<=mx*m){
            ans[i]=(n-i)/m;
        }
    }
    for(int i=0;i<=n;i++)printf("%d ", ans[i]);
}