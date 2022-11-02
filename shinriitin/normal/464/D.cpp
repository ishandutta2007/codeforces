#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
typedef long double ld; 

const int MAXN=1000; 

int n,k,cur;

ld dp[2][MAXN];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=n;i;--i){
        cur^=1;
        int B=701;
        rep(j,1,B){
            dp[cur][j]=(dp[cur^1][j]+(1.+j)/2)*j;
            dp[cur][j]+=(dp[cur^1][j+1]+j);
            dp[cur][j]/=j+1;
            dp[cur][j]+=dp[cur^1][j]*(k-1);
            dp[cur][j]/=k;
        }
    }
    ld ans=dp[cur][1]*k;
    printf("%.20f\n",(double)ans);
    return 0;
}