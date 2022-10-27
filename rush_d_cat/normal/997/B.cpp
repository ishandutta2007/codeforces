#include <iostream>
using namespace std;
typedef long long LL;
LL n;

int dp[102][10002], ans[100];
void test(){
    dp[0][0]=1;
    for(int i=1;i<=30;i++){
        for(int j=1;j<=10000;j++){
            if(j>=1&&dp[i-1][j-1]) dp[i][j]=1;
            if(j>=5&&dp[i-1][j-5]) dp[i][j]=1;
            if(j>=10&&dp[i-1][j-10]) dp[i][j]=1;
            if(j>=50&&dp[i-1][j-50]) dp[i][j]=1;
        }
        int cnt=0;
        for(int j=1;j<=10000;j++) cnt+=dp[i][j];
        ans[i]=cnt;
        //printf("%d %d\n", i, cnt);
    }
}

int main() {
    test();
    cin>>n;
    if(n<20) printf("%d\n", ans[n]);
    else printf("%lld\n", ans[11]+(n-11)*49);
}